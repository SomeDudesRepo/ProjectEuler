#include "problem07.h"

#include <cassert>
#include <string>

#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>

#include "../log.h"
#include "../primes.h"

Problem07::Problem07(const int& nth)
    :   BaseRunnable(GetNthPrime(nth)) {}
