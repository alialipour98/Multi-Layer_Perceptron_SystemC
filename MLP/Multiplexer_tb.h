#include "Multiplexer.h"

SC_MODULE(Multiplexer_tb)
{
	sc_signal <sc_logic>      SEL;
	sc_signal <sc_lv<8>>  INPUT_0;
	sc_signal <sc_lv<8>>  INPUT_1;
	sc_signal <sc_lv<8>>  OUTPUT;

	Mux2to1<8>* Multplex;

	SC_CTOR(Multiplexer_tb)
	{
		Multplex = new Mux2to1<8>("Multiplexer");

		Multplex->SEL(SEL);
		Multplex->INPUT_0(INPUT_0);
		Multplex->INPUT_1(INPUT_1);
		Multplex->OUTPUT(OUTPUT);

		SC_THREAD(inputing);
	}

	void inputing();
};

void Multiplexer_tb::inputing()
{
	INPUT_0 = sc_lv<8>(12);
	INPUT_1 = sc_lv<8>(-13);

	SEL = SC_LOGIC_0;
	wait(10, SC_NS);
	SEL = SC_LOGIC_1;
	wait(10, SC_NS);

	INPUT_0 = sc_lv<8>(-12);
	INPUT_1 = sc_lv<8>(-12);

	SEL = SC_LOGIC_0;
	wait(10, SC_NS);
	SEL = SC_LOGIC_1;
	wait(10, SC_NS);

	INPUT_0 = sc_lv<8>(15);
	INPUT_1 = sc_lv<8>(6);

	SEL = SC_LOGIC_0;
	wait(10, SC_NS);
	SEL = SC_LOGIC_1;
	wait(10, SC_NS);

	INPUT_0 = sc_lv<8>(45);
	INPUT_1 = sc_lv<8>(2);

	SEL = SC_LOGIC_0;
	wait(10, SC_NS);
	SEL = SC_LOGIC_1;
	wait(10, SC_NS);
}
