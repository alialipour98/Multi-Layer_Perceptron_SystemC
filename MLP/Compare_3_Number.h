#include <systemc.h>

SC_MODULE(Adder) {
	sc_in  <sc_lv<8>>  INPUT_1;
	sc_in  <sc_lv<8>>  INPUT_2;
	sc_in  <sc_lv<8>>  INPUT_3;
	sc_out <sc_lv<2>>  OUTPUT;

	SC_CTOR(Adder)
	{
		SC_METHOD(Adding);
		sensitive << INPUT_1 << INPUT_2 << INPUT_3;
	}
	void Adding()
	{
		sc_lv<2> vout;
		if ((sc_int<8>) INPUT_1 > (sc_int<8>) INPUT_2)
		{
			if ((sc_int<8>) INPUT_1 > (sc_int<8>) INPUT_3)
				vout = sc_lv<2>(0);
		}
		else if ((sc_int<8>) INPUT_2 > (sc_int<8>) INPUT_1)
		{
			if ((sc_int<8>) INPUT_2 > (sc_int<8>) INPUT_3)
				vout = sc_lv<2>(1);
		}
		else if ((sc_int<8>) INPUT_3 > (sc_int<8>) INPUT_1)
		{
			if ((sc_int<8>) INPUT_3 > (sc_int<8>) INPUT_2)
				vout = sc_lv<2>(2);
		}
		OUTPUT = vout;
	}
};




