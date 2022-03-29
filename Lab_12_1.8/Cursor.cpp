// Cursor.cpp
#include "Cursor.h"
#include <sstream>
#include <iostream>
using namespace std;

string showbits(const void* ptr, int bytes) {
	stringstream ss;
	unsigned char* arr = (unsigned char*)ptr;

	for (int i = 0; i < bytes; i++)
	{
		for (int j = 0; j < 8; j++)
			arr[i] & (1 << j) ? ss << "1" : ss << "0";
		ss << " ";
	}
	return ss.str();
}


void Cursor::LongLong::Init(long _high, unsigned long _low)
{
	setHigh(_high);
	setLow(_low);
}

void Cursor::LongLong::display() const
{
	cout << toString() << endl;
}

string Cursor::LongLong::toString() const
{
	long long l = getLongLong();
	stringstream ss;
	ss << "high: " << high << " low: " << low << endl
		<< "high: " << showbits(&high, sizeof(high)) << " low: " << showbits(&low, sizeof(low)) << endl;
	return ss.str();
}

long long Cursor::LongLong::getLongLong() const
{
	long a[] = { high, low };
	return *(long long*)&a;
}

Cursor::LongLong add(Cursor::LongLong l1, Cursor::LongLong l2)
{
	Cursor::LongLong ll;

	long long ll1 = l1.getLongLong();
	long long ll2 = l2.getLongLong();
	long long r = ll1 + ll2;

	long* res = (long*)&r;

	ll.high = res[0];
	ll.low = res[1];
	return ll;
}

Cursor::LongLong sub(Cursor::LongLong l1, Cursor::LongLong l2)
{
	Cursor::LongLong ll;
	long long ll1 = l1.getLongLong();
	long long ll2 = l2.getLongLong();
	long long r = ll1 - ll2;

	long* res = (long*)&r;

	ll.high = res[0];
	ll.low = res[1];
	return ll;
}

Cursor::LongLong mult(Cursor::LongLong l1, Cursor::LongLong l2)
{
	Cursor::LongLong ll;
	long long ll1 = l1.getLongLong();
	long long ll2 = l2.getLongLong();
	long long r = ll1 * ll2;

	long* res = (long*)&r;

	ll.high = res[0];
	ll.low = res[1];
	return ll;
}

Cursor::LongLong div(Cursor::LongLong l1, Cursor::LongLong l2)
{
	Cursor::LongLong ll;
	long long ll1 = l1.getLongLong();
	long long ll2 = l2.getLongLong();
	long long r = ll1 / ll2;

	long* res = (long*)&r;

	ll.high = res[0];
	ll.low = res[1];
	return ll;
}

Cursor::LongLong mod(Cursor::LongLong l1, Cursor::LongLong l2)
{
	Cursor::LongLong ll;
	long long ll1 = l1.getLongLong();
	long long ll2 = l2.getLongLong();
	long long r = ll1 % ll2;

	long* res = (long*)&r;

	ll.high = res[0];
	ll.low = res[1];
	return ll;
}

bool lessthan(Cursor::LongLong l1, Cursor::LongLong l2)
{
	return l1.getLongLong() < l2.getLongLong();
}

bool greatthan(Cursor::LongLong l1, Cursor::LongLong l2)
{
	return l1.getLongLong() > l2.getLongLong();
}

bool equal(Cursor::LongLong l1, Cursor::LongLong l2)
{
	return l1.getLongLong() == l2.getLongLong();
}

bool nequal(Cursor::LongLong l1, Cursor::LongLong l2)
{
	return !equal(l1, l2);
}


bool Cursor::Init(unsigned int x, unsigned int y, char s, bool v)
{
    if (s > 0 && s <= 15) {
        position.Init(x, y);
        size = s;
        view = v;
        return true;
    }
    else
        return false;
}

void Cursor::read()
{
    unsigned int x, y;
    int s;
    bool v;
    do
    {
        cout << "¬вед≥ть позиц≥ю по x: "; cin >> x;
        cout << "¬вед≥ть позиц≥ю по y: "; cin >> y;
        cout << "¬вед≥ть розм≥р: "; cin >> s;
        cout << "¬ед≥ть вид курсору(1 - horizontal, 0 - vertical): "; cin >> v;
    } while (!Init(x, y, s, v));
}

void Cursor::display() const
{
    cout << toString() << endl;
}

string Cursor::toString() const
{
    stringstream ss;
    ss << '(' << position.getHigh() << ", " << position.getLow() << ") size: " << (int)size << (view ? " horizontal" : " vertical");
    return ss.str();
}

bool Cursor::setPosition(LongLong ll)
{
    if (ll.getHigh() >= 0)
    {
        position = ll;
        return true;
    }
    else
        return false;
}

bool Cursor::setSize(char s)
{
    if (s > 0 && s < 16)
    {
        size = s;
        return true;
    }
    else
        return false;
}

void Cursor::move(long x, long y)
{
    Hide();

    LongLong ll;
    ll.Init(x, y);
    position = add(position, ll);

    Show();
}

void Cursor::changeView()
{
    view = !view;
}

void Cursor::SizeUp()
{
    setSize(size + 1);
}

void Cursor::SizeDown()
{
    setSize(size - 1);
}

void Cursor::Show()
{
    cout << "Cursor shows" << endl;
}

void Cursor::Hide()
{
    cout << "Cursor hides" << endl;
}
