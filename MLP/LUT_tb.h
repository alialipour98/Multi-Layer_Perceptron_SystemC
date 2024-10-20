#include "LUT.h"

SC_MODULE(LUT_tb)
{
	sc_signal<sc_lv<8>>    addr;

	sc_signal<sc_lv<8>>  OUTPUT;

	LUT* LUT_WB;

	SC_CTOR(LUT_tb)
	{
		LUT_WB = new LUT("LUT");
		LUT_WB->addr(addr);
		LUT_WB->OUTPUT(OUTPUT);

		SC_THREAD(inputing);
	}

	void inputing();
};

void LUT_tb::inputing()
{
	addr = sc_lv<8>(0);
	wait(10, SC_NS);
	addr = sc_lv<8>(12);
	wait(10, SC_NS);
	addr = sc_lv<8>(17);
	wait(10, SC_NS);
	addr = sc_lv<8>(19);
	wait(10, SC_NS);
	addr = sc_lv<8>(20);
	wait(10, SC_NS);
}
