#include "Comparator.h"

SC_MODULE(Comparator_tb)
{
	sc_signal <sc_lv<8>> INPUT_1;
	sc_signal <sc_lv<8>> INPUT_2;
	sc_signal <sc_logic> EQ     ;

	Comparator<8>* cmp;

	SC_CTOR(Comparator_tb)
	{
		cmp = new Comparator<8>("Comparator");

		cmp->INPUT_1(INPUT_1);
		cmp->INPUT_2(INPUT_2);
		cmp->EQ(EQ);

		SC_THREAD(inputing);
	}

	void inputing();
};

void Comparator_tb::inputing()
{
	INPUT_1 = "00011010";
	INPUT_2 = "00011010";
	wait(10, SC_NS);
	INPUT_1 = "00011001";
	INPUT_2 = "00011000";
	wait(10, SC_NS);
	INPUT_1 = "00100010";
	INPUT_2 = "01111010";
	wait(10, SC_NS);
	INPUT_1 = "01100000";
	INPUT_2 = "01100000";
}
