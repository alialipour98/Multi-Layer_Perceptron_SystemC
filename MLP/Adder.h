#include <systemc.h>

template <int ADD_Size_IN, int ADD_Size_OUT>
SC_MODULE(Adder) {
	sc_in  <sc_lv<ADD_Size_IN>>  INPUT_1;
	sc_in  <sc_lv<ADD_Size_IN>>  INPUT_2;
	sc_out <sc_lv<ADD_Size_OUT>>  OUTPUT;

	SC_CTOR(Adder)
	{
		SC_METHOD(Adding);
		sensitive << INPUT_1 << INPUT_2;
	}
	void Adding()
	{
		sc_lv<ADD_Size_OUT> vout;
		vout   = (sc_int<ADD_Size_IN>) INPUT_1 + (sc_int<ADD_Size_IN>) INPUT_2;
		OUTPUT = vout;
	}
};



