// #include "mlir/Parser/Parser.h"
#include "llvm/Support/CommandLine.h"
#include <iostream>

using namespace llvm;

static cl::opt<std::string> input_filename(cl::Positional, cl::desc("<input>"),
                                           cl::init("-"),
                                           cl::value_desc("filename"));

static cl::opt<std::string> output_filename("o", cl::desc("Output file"),
                                            cl::init("a.out"),
                                            cl::value_desc("filename"));

enum RetVal : int {
  OK = 0,
  ERR,
};

static const int MajorVersion = 0;
static const int MinorVersion = 1;

namespace potato {
struct Program {
  std::vector<std::string> inputs;
  std::string output;
};
}; // namespace potato

static potato::Program *CreateProgram() { return nullptr; }

void PrintVersion(raw_ostream &os) {
  os << "potatoc: " << MajorVersion << "." << MinorVersion << "\n";
}

int main(int argc, char *argv[]) {
  cl::AddExtraVersionPrinter(PrintVersion);

  if (!cl::ParseCommandLineOptions(argc, argv, "potatoc") || argc <= 1) {
    cl::PrintHelpMessage();
    return ERR;
  }

  return OK;
}