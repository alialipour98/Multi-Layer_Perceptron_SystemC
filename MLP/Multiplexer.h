#include <systemc.h>

template <int MUX_Width>
SC_MODULE(Mux2to1)
{
	sc_in<sc_logic>              SEL;
	sc_in<sc_lv<MUX_Width>>  INPUT_0;
	sc_in<sc_lv<MUX_Width>>  INPUT_1;
	sc_out<sc_lv<MUX_Width>>  OUTPUT;

	SC_CTOR(Mux2to1)
	{
		SC_METHOD(muxing);
		sensitive << INPUT_0 << INPUT_1 << SEL;
	}
	void muxing();
};

template <int MUX_Width>
void Mux2to1<MUX_Width>::muxing() {
	if (SEL->read() == '1') 
		OUTPUT->write(INPUT_1);
	else
		OUTPUT->write(INPUT_0);
}

