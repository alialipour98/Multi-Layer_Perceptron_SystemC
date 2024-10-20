#include <systemc.h>

template <int Comp_Width>
class Comparator : public sc_module {
public:
	sc_in <sc_lv<Comp_Width>> INPUT_1;
	sc_in <sc_lv<Comp_Width>> INPUT_2;
	sc_out<sc_logic>               EQ;

	SC_HAS_PROCESS(Comparator);
	Comparator(sc_module_name);

	void comparing();
};

template <int Comp_Width>
Comparator<Comp_Width>::Comparator(sc_module_name)
{
	SC_METHOD(comparing);
	sensitive << INPUT_1 << INPUT_2;
}

template <int Comp_Width>
void Comparator<Comp_Width>::comparing()
{
	if (INPUT_1.read() == INPUT_2.read())
		EQ.write(SC_LOGIC_1);
	else
		EQ.write(SC_LOGIC_0);
};





