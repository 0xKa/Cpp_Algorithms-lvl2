//Encrypt/Decrypt text

#include <iostream>
#include <string>

using namespace std;

string ReadText(string massage)
{
	string text;
	cout << massage << endl;
	getline(cin, text);
	return text;


}

string EncryptText(string text, short EncryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char( (int)text[i] + EncryptionKey );
	}
	return text;
}

string DecryptText(string text, short EncryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char((int)text[i] - EncryptionKey);
	}
	return text;
}

int main()
{
	const short EncryptionKey = 10000;

	string Text = ReadText("Enter a Text:");
	string EncryptedText = EncryptText(Text,EncryptionKey);
	//string DecryptedText = DecryptText(EncryptedText,EncryptionKey);

	cout << "\nText After Encrypted : " << EncryptedText << endl;
	//cout << "\nText After Decrypted : " << DecryptedText << endl;



	cout << endl << endl;
	return 0;
}
