#include "Adder.h"
#include "Multiplier.h"
#include "Multiplexer.h"
#include "Accumulator.h"
#include "Register_src.h"
#include "Register_File.h"
#include "Address_Counter.h"

template <int Counter_Width, int Comp_Value>
SC_MODULE(Datapath)
{
	sc_in     <sc_logic>    Clock;
	sc_in     <sc_logic>    Reset;
	sc_in     <sc_logic>   ReadRF;
	sc_in     <sc_logic>      INC;
	sc_in     <sc_logic>    Load1;
	sc_in     <sc_logic>    Load2;
	sc_in     <sc_logic>   LoadRF;
	sc_in     <sc_logic>  LoadACC;
	sc_in     <sc_logic>    INIT1;
	sc_in     <sc_logic>    INIT2;
	sc_in     <sc_logic>   INIT_C;
	sc_in     <sc_logic> INIT_ACC;
	sc_out    <sc_logic>     Done;

	sc_in     <sc_lv<8>>  INPUT_0;
	sc_in     <sc_lv<8>>  INPUT_1;
	sc_in     <sc_lv<8>>  INPUT_2;
	sc_in     <sc_lv<8>>  INPUT_3;
	sc_in     <sc_lv<8>>  INPUT_4;
	sc_in     <sc_lv<8>>  INPUT_5;
	sc_in     <sc_lv<8>>  INPUT_6;
	sc_in     <sc_lv<8>>  INPUT_7;
	sc_in     <sc_lv<8>>  INPUT_8;
	sc_in     <sc_lv<8>>  INPUT_9;

	sc_in     <sc_lv<8>>  Weight_0;
	sc_in     <sc_lv<8>>  Weight_1;
	sc_in     <sc_lv<8>>  Weight_2;
	sc_in     <sc_lv<8>>  Weight_3;
	sc_in     <sc_lv<8>>  Weight_4;
	sc_in     <sc_lv<8>>  Weight_5;
	sc_in     <sc_lv<8>>  Weight_6;
	sc_in     <sc_lv<8>>  Weight_7;
	sc_in     <sc_lv<8>>  Weight_8;
	sc_in     <sc_lv<8>>  Weight_9;

	sc_in     <sc_lv<8>>      Bias;

	sc_out    <sc_lv<8>>  OUTPUT_I;
	sc_out    <sc_lv<8>> OUTPUT_II;

	sc_signal <sc_logic>       SEL;

	sc_signal <sc_lv<8>>         RF_W;
	sc_signal <sc_lv<8>>        RF_IN;
	sc_signal <sc_lv<8>>       MUX_IN;
	sc_signal <sc_lv<8>>      BUF_OUT;
	sc_signal <sc_lv<8>>      ZeroReg;
	sc_signal <sc_lv<4>>      Addr_RC;
	sc_signal <sc_lv<16>>     ACC_OUT;
	sc_signal <sc_lv<16>>     ADD_OUT;
	sc_signal <sc_lv<16>>     MUL_OUT;
	sc_signal <sc_lv<16>>   Bias_INIT;
	sc_signal <sc_lv<8>>     Reg1_OUT;
	sc_signal <sc_lv<8>>     Reg2_OUT;
	sc_signal <sc_lv<8>>   OUTPUT_Int;

	AccRegister     <16>*                                Acc;
	dRegister       <8>*                                Reg1;
	dRegister       <8>*                                Reg2;
	Adder           <16, 16>*                            Add;
	Register_File   <4, 8>*                        RegFile_0;
	Register_File   <4, 8>*                        RegFile_1;
	Mult            <8, 16>*                      Multiplier;
	Mux2to1         <8>*                         Multiplexer;
	Address_Counter <Counter_Width, Comp_Value>* AddrCounter;

	SC_CTOR(Datapath)
	{
		RegFile_0 = new Register_File<4, 8>("RegFile_0");
		RegFile_0->Clock(Clock);
		RegFile_0->Reset(Reset);
		RegFile_0->Load(LoadRF);
		RegFile_0->ReadEn(ReadRF);
		RegFile_0->addr(Addr_RC);
		RegFile_0->INPUT_0(INPUT_0);
		RegFile_0->INPUT_1(INPUT_1);
		RegFile_0->INPUT_2(INPUT_2);
		RegFile_0->INPUT_3(INPUT_3);
		RegFile_0->INPUT_4(INPUT_4);
		RegFile_0->INPUT_5(INPUT_5);
		RegFile_0->INPUT_6(INPUT_6);
		RegFile_0->INPUT_7(INPUT_7);
		RegFile_0->INPUT_8(INPUT_8);
		RegFile_0->INPUT_9(INPUT_9);
		RegFile_0->OUTPUT(RF_IN);

		RegFile_1 = new Register_File<4, 8>("RegFile_0");
		RegFile_1->Clock(Clock);
		RegFile_1->Reset(Reset);
		RegFile_1->Load(LoadRF);
		RegFile_1->ReadEn(ReadRF);
		RegFile_1->addr(Addr_RC);
		RegFile_1->INPUT_0(Weight_0);
		RegFile_1->INPUT_1(Weight_1);
		RegFile_1->INPUT_2(Weight_2);
		RegFile_1->INPUT_3(Weight_3);
		RegFile_1->INPUT_4(Weight_4);
		RegFile_1->INPUT_5(Weight_5);
		RegFile_1->INPUT_6(Weight_6);
		RegFile_1->INPUT_7(Weight_7);
		RegFile_1->INPUT_8(Weight_8);
		RegFile_1->INPUT_9(Weight_9);
		RegFile_1->OUTPUT(RF_W);

		AddrCounter = new Address_Counter<Counter_Width, Comp_Value> ("Address Counter");
		AddrCounter->Clock(Clock);
		AddrCounter->Reset(Reset);
		AddrCounter->INIT(INIT_C);
		AddrCounter->INC(INC);
		AddrCounter->Done(Done);
		AddrCounter->OUTPUT(Addr_RC);

		Reg1 = new dRegister<8>("Register_src_0");
		Reg1->Clock(Clock);
		Reg1->Reset(Reset);
		Reg1->Load(Load1);
		Reg1->INIT(INIT1);
		Reg1->INPUT(RF_IN);
		Reg1->OUTPUT(Reg1_OUT);

		Reg2 = new dRegister<8>("Register_src_1");
		Reg2->Clock(Clock);
		Reg2->Reset(Reset);
		Reg2->Load(Load2);
		Reg2->INIT(INIT2);
		Reg2->INPUT(RF_W);
		Reg2->OUTPUT(Reg2_OUT);

		Multiplier = new Mult<8, 16>("Multiplier");
		Multiplier->INPUT_1(Reg1_OUT);
		Multiplier->INPUT_2(Reg2_OUT);
		Multiplier->OUTPUT(MUL_OUT);

		Add = new Adder<16, 16>("Adder");
		Add->INPUT_1(MUL_OUT);
		Add->INPUT_2(ACC_OUT);
		Add->OUTPUT(ADD_OUT);

		Acc = new AccRegister<16>("Accumulator");
		Acc->Clock(Clock);
		Acc->Reset(Reset);
		Acc->Load(LoadACC);
		Acc->INIT(INIT_ACC);
		Acc->INPUT(ADD_OUT);
		Acc->Bias_In(Bias_INIT);
		Acc->OUTPUT(ACC_OUT);

		Multiplexer = new Mux2to1<8>("Multiplexer");
		Multiplexer->SEL(SEL);
		Multiplexer->INPUT_0(MUX_IN);
		Multiplexer->INPUT_1(ZeroReg);
		Multiplexer->OUTPUT(OUTPUT_Int);

		SC_METHOD(assignment);
		sensitive << OUTPUT_Int << ACC_OUT << ZeroReg << Bias;
	}

	void assignment();
};

template <int Address_Width, int Comp_Value>
void Datapath<Address_Width, Comp_Value>::assignment()
{
	OUTPUT_I.write(OUTPUT_Int);
	OUTPUT_II.write(ACC_OUT.read().range(13, 6));
	MUX_IN.write(ACC_OUT.read().range(13, 6));
	ZeroReg.write(sc_lv<8>(0));
	Bias_INIT.write(concat(sc_lv<8>(Bias.read()[7]), Bias.read()));
	SEL.write(ACC_OUT.read().get_bit(13));
}
