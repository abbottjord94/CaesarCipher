//C++ Challenge Caesar Cipher encrypt/decrypt

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

string read_file(fstream &infile);
string encrypt(string msg, int shift);
string decrypt(string msg, int shift);

int main(int argc, char* argv[]) {
	string message, decrypted_message;
	int shift_val = 0;
	fstream infile;
	infile.open("message.txt");
	message = read_file(infile);
	cout << "**********MESSAGE INTERCEPTED**********";
	cout << "\n\n\nENTER DECRYPTION KEY:";
	cin >> shift_val;
	decrypted_message = decrypt(message, shift_val);
	decrypted_message.pop_back();
	cout << "MESSAGE DECRYPTED: " << decrypted_message << endl;
	return 0;
}

string read_file(fstream &infile) {
	string file_data(std::istreambuf_iterator<char>(infile) ,(std::istreambuf_iterator<char>()));
	infile.close();
	return file_data;
}

string decrypt(string msg, int shift) {
	string decrypted_msg;
	decrypted_msg.resize(msg.size());
	for(int i=0; i<msg.length(); i++) {
		decrypted_msg[i] = toupper(msg[i]);
		if(msg[i] == ' ') {
			decrypted_msg[i] = msg[i];
		} else {
			decrypted_msg[i] = 65+((msg[i] - shift)%26);
		}
	}
	return decrypted_msg;
}
