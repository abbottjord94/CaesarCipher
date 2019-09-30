//C++ Challenge Caesar Cipher Decryption

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

string read_file(fstream &infile);
string decrypt(string msg, int shift);

//Main function
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

//Reads in the message.txt file and stores the contents in a string
string read_file(fstream &infile) {
	string file_data(std::istreambuf_iterator<char>(infile) ,(std::istreambuf_iterator<char>()));
	infile.close();
	return file_data;
}

//Write your Caesar Cipher decryption function here
//Remember that only letters are encrypted by the Caesar cipher. Spaces and newlines ('\n') are not

string decrypt(string msg, int shift) {
	string decrypted_msg;
	decrypted_msg.resize(msg.size());
	for(int i=0; i<msg.size(); i++) {
		if(msg[i] == ' ' || msg[i] == '\n') {
			decrypted_msg[i] = msg[i];
		} else {
			decrypted_msg[i] = 65+((msg[i] - shift)%26);
		}
	}
	return decrypted_msg;
}
