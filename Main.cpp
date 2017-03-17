#include <iostream>

#include "Test_TP4.h"

int main() {
	Test_TP4 TestCorrection;

	TestCorrection.executeProxyTest();
	TestCorrection.executeTemplateMethodTest();
	TestCorrection.executeCompositeTest();

	return 0;
}