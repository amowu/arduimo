#ifndef Telegraph_h
#define Telegraph_h

class Telegraph
{
public:
	Telegraph(const int output_pin, const int dit_length);
	void send_message(const char* message);

private:
	void dit();
	void dah();
	void output_code(const char* code);
	void output_symbol(const int length);

	int _output_pin;
	int _dit_length;
	int _dah_length;
};

#endif