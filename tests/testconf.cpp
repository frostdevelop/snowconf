#include "snowconf.h"
#include <iostream>
#include <string>

int main() {
  wsnowconf test("test.sno");
  //test.writeVar("test", 3);
  test.writeComment("mr beast");
  test.writeHeader("REASONS");
  test.writeVar("gaming", "mr beast");
  test.writeVar("yes", "logan paul forest");
  test.close();
  // delete test;
  wsnowconf testf("testf.sno");
  testf.writeComment("Copyright Frost 2025");
  testf.writeHeader("FR-AUTH");
  testf.writeVar("token", "f72no39jzl20expt0xmgo93");
  testf.writeVar("username", "carl-watson");
  testf.writeVar("time", 1737215228366);
  testf.writeVar("worth", 25.6);
  testf.writeVar("hasSnow", true);
  testf.close();
  // delete testf; no dynamic allocation
  rsnowconf testfr("testf.sno");
  snow::snowVal *data;
  while ((data = testfr.getNVar()) != nullptr) {
    switch (data->type) {
    case snow::snowVal::HEADER:
      std::cout << "HEADER:"+data->name << std::endl;
      break;
    case snow::snowVal::STRING:
      std::cout << "STRING:"+data->name << " = " << data->strVal << std::endl;
      break;
    case snow::snowVal::INT:
      std::cout << "INT:"+data->name << " = " << data->intVal << std::endl;
      break;
    case snow::snowVal::FLOAT:
      std::cout << "FLOAT:"+data->name << " = " << data->floatVal << std::endl;
      break;
    case snow::snowVal::BOOL:
      std::cout << "BOOL:"+data->name << " = " << data->boolVal << std::endl;
      break;
    }
  }
  // std::cout << data->type << std::endl;
  testfr.close();
}