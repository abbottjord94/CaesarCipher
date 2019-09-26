//C++ Challenge Caesar Cipher encrypt/decrypt

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void print_usage();
string read_file(fstream &infile);
int write_file(fstream &outfile, string msg);
string encrypt(string msg, int shift);

int main(int argc, char* argv[]) {
	if(argc < 3) {
		print_usage();
	} else {
		string message;
		string filename = argv[1];
		string savefile = argv[2];
		int shift_val = 0;
		fstream outfile, infile;

		infile.open(filename);
		outfile.open(savefile);

		message = read_file(infile);

		cout << "Enter encryption key:";
		cin >> shift_val;

		if(write_file(outfile, encrypt(message, shift_val))) {
			cout << "Message encrypted successfully." << endl;
		} else {
			cout << "Error: Message not encrypted." << endl;
		}

		return 0;
	}
}

void print_usage() {
	cout << "Usage: ./encrypt [message to encrypt] [save file location]\n";
	exit(1);
}

string read_file(fstream &infile) {
        string file_data(std::istreambuf_iterator<char>(infile) ,(std::istreambuf_iterator<char>()));
        infile.close();
        return file_data;
}

int write_file(fstream &outfile, string msg) {
	outfile << msg;
	outfile.close();
	return 1;
}

string encrypt(string msg, int shift) {
	string encrypted_msg;
	encrypted_msg.resize(msg.size());
	for(int i=0; i<msg.length(); i++) {
		// encrypted_msg[i]=toupper(msg[i]);
		if(msg[i] == ' ' || msg[i] == '\n' || msg[i] == '\000' || msg[i] == '\t') {
			encrypted_msg[i] = msg[i];
		} else {
			encrypted_msg[i] = 65+((msg[i] + shift)%26);
		}
	}
	return encrypted_msg;
}
