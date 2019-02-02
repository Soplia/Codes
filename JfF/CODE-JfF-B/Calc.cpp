#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

char compare[48][48];

int calc( int a , int b , char op ){
	if( op == '+' )
		return a + b;
	else if( op == '-' )
		return a - b;
	else if( op == '*' )
		return a * b;
	else
		return a / b;
}
bool isnumber( char c ){
	return '0' <= c && c <= '9';
}
char cmp( char a , char b ){
	return compare[ a ][ b ];
}


int main(){
	char c[] = { '+' , '-' , '*' , '/' , '(' , ')' , '#' };
	int i=0,j=0;
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '<';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = '<';
	compare[ c[i++] ][ c[j] ] = ' ';
	compare[ c[i++] ][ c[j] ] = '<';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '=';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = ' ';
	i=0,j++;
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = ' ';
	compare[ c[i++] ][ c[j] ] = '>';
	compare[ c[i++] ][ c[j] ] = '=';
	i=0,j++;
	int s1[200];
	char s2[200];
	int t1=-1,t2=-1;
	string str = "(20+2)*(6/2)#";
	s2[ ++t2 ] = '#';
	for( int i = 0 ; i < str.length() ; i++ ){
		char c = str[ i ];
		if( isnumber( c ) )
			s1[ ++t1 ] = c - 48;
		else{
			char result = cmp( s2[ t2 ] , c );
			if( result == '<' )
				s2[ ++t2 ] = c;
			else if( result == '=' )
				t2--;
			else if( result == '>' ){
				int a = s1[ t1-- ];
				int b = s1[ t1-- ];
				char op = s2[ t2-- ];
				s1[ ++t1 ] = calc( a , b , op );
				i--;
			}
		}
		/*for( int k = 0 ; k <= t1 ; k++ )
			cout << s1[ k ] << ' ';
		cout << endl;
		for( int k = 0 ; k <= t2 ; k++ )
			cout << s2[ k ] << ' ';
		cout << endl;
		system( "pause" );*/
	}
	cout << s1[ 0 ] << endl;
	return 0;
}

