#include <systemc.h>

template <int Address_Width>
class nBitCounter : public sc_module {
public:
	sc_in  <sc_logic>             Clock ;
	sc_in  <sc_logic>             Reset ;
	sc_in  <sc_logic>             INIT  ;
	sc_in  <sc_logic>             INC   ;
	sc_out <sc_lv<Address_Width>> OUTPUT;

	sc_uint<Address_Width>       cnt_val;

	SC_HAS_PROCESS(nBitCounter);
	nBitCounter(sc_module_name);

	void counting();
};

template <int Address_Width>
nBitCounter<Address_Width>::nBitCounter(sc_module_name)
{
	SC_METHOD(counting);
	sensitive << Clock << Reset;
}

template <int Address_Width>
void nBitCounter<Address_Width>::counting()
{
	sc_lv<Address_Width> tmp;
	if (Reset == '1')
	{
		for (int i = 0; i < Address_Width; i++)
			tmp[i] = sc_logic(0);
		cnt_val = tmp;
	}
	else if ((Clock->event()) && (Clock == '1')) {
		if (INIT == '1')
		{
			for (int i = 0; i < Address_Width; i++)
				tmp[i] = sc_logic(0);
			cnt_val = tmp;
		}
		else if (INC == '1')
			cnt_val = cnt_val + 1;
		OUTPUT = cnt_val;
	}
};

