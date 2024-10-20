#include <systemc.h>

template <int SRC_Width>
class dRegister : public sc_module {
public:
	sc_in <sc_logic> Clock;
	sc_in <sc_logic> Reset;
	sc_in <sc_logic> Load ;
	sc_in <sc_logic> INIT ;

	sc_in  <sc_lv<SRC_Width>>  INPUT;
	sc_out <sc_lv<SRC_Width>> OUTPUT;

	SC_HAS_PROCESS(dRegister);
	dRegister(sc_module_name);

	void registering();
};

template <int SRC_Width>
dRegister<SRC_Width>::dRegister(sc_module_name)
{
	SC_METHOD(registering);
	sensitive << Clock << Reset;
}

template <int SRC_Width>
void dRegister<SRC_Width>::registering()
{
	sc_lv<SRC_Width> tmp;
	if (Reset == '1')
	{
		for (int i = 0; i < SRC_Width; i++)
			tmp[i] = sc_logic(0);
		OUTPUT = tmp;
	}
	else if ((Clock->event()) && (Clock == '1')) {
		if (INIT == '1')
		{
			for (int i = 0; i < SRC_Width; i++)
				tmp[i] = sc_logic(0);
			OUTPUT = tmp;
		}
		else if (Load == '1')
			OUTPUT = INPUT;
	}
};
