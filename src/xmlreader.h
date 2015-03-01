#ifndef XMLREADER_H
#define XMLREADER_H

#include <memory>
#include <vector>

#include <QFile>

typedef std::vector<std::string> Problems;
typedef std::vector<std::string> Parameters;

class XmlReader
{
public:
    XmlReader(const std::string& filePath);
    Problems GetAvailableProblems() const;
    Parameters GetProblemParameters(const int &problemId) const;

private:
    std::unique_ptr<QFile> mFile;
};

#endif // XMLREADER_H
