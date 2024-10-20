#include <systemc.h>

template <int Mul_Size_IN, int Mul_Size_OUT> 
SC_MODULE(Mult) {
	sc_in <sc_lv<Mul_Size_IN> >  INPUT_1;
	sc_in <sc_lv<Mul_Size_IN> >  INPUT_2;
	sc_out <sc_lv<Mul_Size_OUT>>  OUTPUT;

	SC_CTOR(Mult)
	{
		SC_METHOD(multiplying);
		sensitive << INPUT_1 << INPUT_2;
	}

	void multiplying()
	{
		sc_lv <Mul_Size_OUT> vout;
		vout   = (sc_int<Mul_Size_IN>) INPUT_1 * (sc_int<Mul_Size_IN>) INPUT_2;
		OUTPUT = vout;
	}
};





