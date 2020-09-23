#include <iostream>

using namespace std;

class TransNumber{
	public:
		double real, tran;

		TransNumber add(TransNumber a, TransNumber b){
			TransNumber c;
			c.real = a.real + b.real;
			c.tran = a.tran + b.tran;
			return c;
		}

		TransNumber sub(TransNumber a, TransNumber b){
			TransNumber c;
			c.real = a.real - b.real;
			c.tran = a.tran - b.tran;
			return c;
		}

		TransNumber mul(TransNumber a, TransNumber b){
			TransNumber  c;
			c.real = a.real*b.real-a.tran*b.tran;
			c.tran = a.real*b.tran+a.tran*b.real;
			return c;
		}

		TransNumber div(TransNumber a, TransNumber b){
			TransNumber c;
			c.real = a.real*b.real+a.tran*b.tran;
			c.tran = a.tran*b.real-a.real*b.tran;
			return c;
		}

		bool equ(TransNumber a, TransNumber b){
			return((a.real == b.real) && (a.tran == b.tran));
		}

		bool comp(TransNumber a, TransNumber b){
			return((a.real + a.tran) < (b.real + b.tran));
		}
};

int main(){
	TransNumber a, b, c, d;
	int action = 0, i = 0;
	double s, constant_a = 0, real_a = 0, constant_b= 0, real_b = 0 ;

	TransNumber objTrans;

	cout << "Выберите действие:" << endl 
		 << "1. Ввести пары чисел" << endl
		 << "2. Показать введеные пары чисел"  << endl 
		 << "3. Сумма чисел"  << endl 
		 << "4. Разность чисел"  << endl 
		 << "5. Умножение чисел" << endl 
	     << "6. Деление первого на второе" << endl 
		 << "7. Деление второго на первое" << endl 
	     << "8. Проверка на равенство" << endl 
	     << "9. Операция сравнения" << endl 
	     << "0. Завершить программу" << endl; 

	while (1) {
		action = getchar();
		switch (action) {
			case('1'):
				cout << "Введите две пары чисел (напр. 2 5 3 = (2,5*3)" << endl;
				cin >> a.real >> real_a >> constant_a;
				cin >> b.real >> real_b >> constant_b;
				a.tran = real_a * constant_a;
				b.tran = real_b * constant_b;
				i = 1;
				cout << "Готово!" << endl;
				break;
			case('2'):
				if(i){
					cout << "(" << a.real << "," << a.tran << ")" << endl;
					cout << "(" << b.real << "," << b.tran << ")" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;
				break;
			case('3'):
				if(i){
					c = objTrans.add(a,b);
					cout << "Сумма: (" << c.real << "," << c.tran << ")" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;
				break;
			case('4'):
				if(i){
					c = objTrans.sub(a,b);
					cout << "Разность: (" << c.real << "," << c.tran << ")" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;
				break;
			case('5'):
				if(i){
					c = objTrans.mul(a,b);
					cout << "Умножение: (" << c.real << "," << c.tran << ")" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;			
				break;
			case('6'):
				if(i){
					c = objTrans.div(a,b);
					cout << "Деление: (" << c.real << "," << c.tran << ")" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;			
				break;
			case('7'):
				c = objTrans.div(b,a);
				cout << "Деление: (" << c.real << "," << c.tran << ")" << endl;
				break;
			case('8'):
				if(i){
					if(objTrans.equ(a,b))
						cout << "Пары чисел равны" << endl;
					else
						cout << "Пары чисел не равны" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;			
				break;
			case('9'):
				if(i){
					if(objTrans.comp(a,b))
						cout << "Пара (" << a.real << "," << a.tran << ")" << 
								" по значению меньше пары (" << b.real << 
								"," << b.tran << ")" << endl;
					else if(objTrans.comp(b,a))
						cout << "Пара (" << a.real << "," << a.tran << ")" << 
								" по значению больше пары (" << b.real << 
								"," << b.tran << ")" << endl;
					else 
						cout << "Пары чисел равны" << endl;
				} else
					cout << "Сначала введите числа!!!" << endl;			
				break;
			case('0'):
				return 0;
		}
	}

	return 0;
}
