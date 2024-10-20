#include "Adder.h"

SC_MODULE(Adder_tb)
{
	sc_signal <sc_lv<16>> INPUT_1;
	sc_signal <sc_lv<16>> INPUT_2;
	sc_signal <sc_lv<16>> OUTPUT;

	Adder<16, 16>* add;

	SC_CTOR(Adder_tb)
	{
		add = new Adder<16, 16>("AdderTest");

		add->INPUT_1(INPUT_1);
		add->INPUT_2(INPUT_2);
		add->OUTPUT(OUTPUT)  ;

		SC_THREAD(inputing);
	}

	void inputing();
};

void Adder_tb::inputing()
{
	INPUT_1 = sc_lv<16>(65);
	INPUT_2 = sc_lv<16>(-14);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<16>(26);
	INPUT_2 = sc_lv<16>(70);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<16>(11);
	INPUT_2 = sc_lv<16>(22);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<16>(90);
	INPUT_2 = sc_lv<16>(13);
}
