#include <systemc.h>

template<int ADDRESS, int WORD_LENGTH>
class Register_File : public sc_module {
public:

	sc_in<sc_logic> Clock;
	sc_in<sc_logic> Reset;
	sc_in<sc_logic> ReadEn;
	sc_in<sc_logic> Load;

	sc_in<sc_lv<ADDRESS>>      addr   ;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_0;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_1;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_2;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_3;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_4;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_5;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_6;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_7;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_8;
	sc_in<sc_lv<WORD_LENGTH>>  INPUT_9;

	sc_out<sc_lv<WORD_LENGTH>> OUTPUT ;

	int addrSpace;
	sc_uint <WORD_LENGTH>* mem;

	void meminit();
	void memread();
	void memwrite();
	void memdump();

	SC_HAS_PROCESS(Register_File);
	Register_File(sc_module_name);
};

template<int ADDRESS, int WORD_LENGTH>
Register_File<ADDRESS, WORD_LENGTH>::Register_File(sc_module_name)
{
	addrSpace = int(pow(2.0, ADDRESS));
	mem       = new sc_uint<WORD_LENGTH>[addrSpace];

	SC_METHOD(memread);
		sensitive << addr << ReadEn;
	SC_METHOD(memwrite);
		sensitive << Reset << Clock;
}

template<int ADDRESS, int WORD_LENGTH>
void Register_File<ADDRESS, WORD_LENGTH>::memwrite() {
	if (Reset.read() == '1')
	{
		for (int i = 0; i < addrSpace; i++)
			mem[i] = 0;
	}
	else if ((Clock.event()) && (Clock == '1'))
	{
		if (Load.read() == '1')
		{
			mem[0] = INPUT_0;
			mem[1] = INPUT_1;
			mem[2] = INPUT_2;
			mem[3] = INPUT_3;
			mem[4] = INPUT_4;
			mem[5] = INPUT_5;
			mem[6] = INPUT_6;
			mem[7] = INPUT_7;
			mem[8] = INPUT_8;
			mem[9] = INPUT_9;
		}
	}
}

template<int ADDRESS, int WORD_LENGTH>
void Register_File<ADDRESS, WORD_LENGTH>::memread() {
	sc_uint<ADDRESS> ad;
	if (ReadEn->read() == '1') {
		ad      = addr;
		OUTPUT  = mem[ad];
	}
}


