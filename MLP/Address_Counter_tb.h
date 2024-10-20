#include "Address_Counter.h"

SC_MODULE(Address_Counter_tb)
{
	sc_signal<sc_logic>   Clock;
	sc_signal<sc_logic>   Reset;
	sc_signal<sc_logic>    INIT;
	sc_signal<sc_logic>     INC;
	sc_signal<sc_logic>    Done;
	sc_signal<sc_lv<4>>  OUTPUT;

	Address_Counter<4, 4>* AdCount;

	SC_CTOR(Address_Counter_tb)
	{
		AdCount = new Address_Counter<4, 4>("Address_Counter");
		AdCount->Clock(Clock);
		AdCount->Reset(Reset);
		AdCount->INIT(INIT);
		AdCount->INC(INC);
		AdCount->Done(Done);
		AdCount->OUTPUT(OUTPUT);
		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Address_Counter_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Address_Counter_tb::inputing()
{
	INIT = SC_LOGIC_0;
	INC  = SC_LOGIC_0;
//  -------------------
	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);
//  -------------------
	INC = SC_LOGIC_1;
	wait(10, SC_NS);
	INC = SC_LOGIC_0;
	wait(10, SC_NS);
//  -------------------
	INC = SC_LOGIC_1;
	wait(10, SC_NS);
	INC = SC_LOGIC_0;
	wait(10, SC_NS);
//  -------------------
	INC = SC_LOGIC_1;
	wait(10, SC_NS);
	INC = SC_LOGIC_0;
	wait(10, SC_NS);
//  -------------------
	INC = SC_LOGIC_1;
	wait(10, SC_NS);
	INC = SC_LOGIC_0;
	wait(10, SC_NS);
}
