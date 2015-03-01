#include "xmlreader.h"

#include <cassert>

#include <QXmlStreamReader>

#include "log.h"

namespace
{

std::unique_ptr<QFile> GetFile(const std::string& filePath)
{
    std::unique_ptr<QFile> file(new QFile(QString::fromStdString(filePath)));
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::string("Filed to open file: " + filePath);
    return std::move(file);
}

}  // namespace

XmlReader::XmlReader(const std::string& filePath)
    :   mFile(GetFile(filePath)) {}

Problems XmlReader::GetAvailableProblems() const
{
    mFile->seek(0);
    QXmlStreamReader reader(mFile.get());
    Problems problems;
    while (!reader.atEnd() && !reader.hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = reader.readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        //If token is StartElement - read it
        if (token == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "problem")
            {
                auto attributes = reader.attributes();
                problems.push_back(attributes.value("id").toString().toStdString());
            }
        }
    }

    if (reader.hasError())
        throw "XML parse error: " + reader.errorString().toStdString();

    reader.clear();
//    mFile->close();

    return problems;
}

Parameters XmlReader::GetProblemParameters(const int& problemId) const
{
    mFile->seek(0);
    QXmlStreamReader reader(mFile.get());
    Parameters params;
    while (!reader.atEnd() && !reader.hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = reader.readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
            continue;

        //If token is StartElement - read it
        if (token == QXmlStreamReader::StartElement)
        {
            if (reader.name() == "problem" && reader.attributes().value("id").toInt() == problemId)
            {
                while (reader.name() != "parameters")
                    reader.readNextStartElement();
                assert(reader.name() == "parameters");

                const int paramCount(reader.attributes().value("count").toInt());
                for (int n(0); n != paramCount; ++n)
                {
                    reader.readNextStartElement();
                    assert(reader.name() == "parameter");
                    params.push_back(reader.readElementText().toStdString());
                }
            }
        }
    }

    if (reader.hasError())
        throw "XML parse error: " + reader.errorString().toStdString();

    reader.clear();

    return params;
}
