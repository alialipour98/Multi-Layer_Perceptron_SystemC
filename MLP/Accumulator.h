#include <systemc.h>

template <int ACC_Width>
class AccRegister : public sc_module {
public:
	sc_in <sc_logic> Clock;
	sc_in <sc_logic> Reset;
	sc_in <sc_logic> Load;
	sc_in <sc_logic> INIT;

	sc_in  <sc_lv<ACC_Width>>   INPUT;
	sc_in  <sc_lv<ACC_Width>> Bias_In;
	sc_out <sc_lv<ACC_Width>>  OUTPUT;

	SC_HAS_PROCESS(AccRegister);
	AccRegister(sc_module_name);

	void registering();
};

template <int ACC_Width>
AccRegister<ACC_Width>::AccRegister(sc_module_name)
{
	SC_METHOD(registering);
	sensitive << Clock << Reset;
}

template <int ACC_Width>
void AccRegister<ACC_Width>::registering()
{
	sc_lv<ACC_Width> tmp;
	if (Reset == '1')
	{
		for (int i = 0; i < ACC_Width; i++)
			tmp[i] = sc_logic(0);
		OUTPUT = tmp;
	}
	else if ((Clock->event()) && (Clock == '1')) {
		if (INIT == '1')
		{
			OUTPUT.write(Bias_In);
		}
		else if (Load == '1')
			OUTPUT = INPUT;
	}
};
