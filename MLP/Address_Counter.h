#include "Comparator.h"
#include "N_Bit_Counter.h"

template <int Address_Width, int Comp_Value>
SC_MODULE(Address_Counter)
{
	sc_in     <sc_logic>              Clock;
	sc_in     <sc_logic>              Reset;
	sc_in     <sc_logic>               INIT;
	sc_in     <sc_logic>                INC;
	sc_out    <sc_logic>               Done;
	sc_out    <sc_lv<Address_Width>> OUTPUT;

	sc_signal <sc_lv<Address_Width>> Counter;
	sc_signal <sc_lv<Address_Width>> cm;

	nBitCounter<Address_Width>* Counter_Reg;
	Comparator <Address_Width>*        COMP;

	SC_CTOR(Address_Counter)
	{
		Counter_Reg = new nBitCounter<Address_Width>("AddressCounter");
		Counter_Reg->Clock(Clock);
		Counter_Reg->Reset(Reset);
		Counter_Reg->INIT(INIT);
		Counter_Reg->INC(INC);
		Counter_Reg->OUTPUT(Counter);

		COMP = new Comparator<Address_Width>("Comparator");
		COMP->EQ(Done);
		COMP->INPUT_1(Counter);
		COMP->INPUT_2(cm);

		SC_METHOD(assignment);
		sensitive << Counter;
	}

	void assignment();
};

template <int Address_Width, int Comp_Value>
void Address_Counter<Address_Width, Comp_Value>::assignment()
{
	OUTPUT.write(Counter);
	cm.write(sc_lv<Address_Width>(Comp_Value));
}



