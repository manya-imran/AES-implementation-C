#include<iostream>
#include<string.h>
#include<cmath>
#include <algorithm>
using namespace std;
int *HexBin(int arr[],int size)	//for hexa digits-4 bits
{
	int fSize=size*4;
	int *binaryAr=new int[fSize];
	for(int i=0;i<size;i++)	//dividing whole array n 8bits blocks to get 8 binary bits
	{
		int hh=(i+1)*4;	//8=ASCII bits
		int gg=i*4;
		for(int j=hh-1;j>=gg;j--)
		{	
			binaryAr[j]=arr[i]%2;		//mod binary digit 1,0
			arr[i]=arr[i]/2;		//divide orig val
		}
	}
	//Print binary
	/*for(int i=0;i<fSize;i++)
	{
		cout<<binaryAr[i]<<" ";
	}
	cout<<endl;*/
	return binaryAr;
}
int *convBin(int arr[],int size)//for ascii 8 bits
{

	//max ascii is 127 1111111 7 bit 
	//ASCII is 7+1 bit thats why
	//1 for the parity bit
	int fSize=size*8;
	int *binaryAr=new int[fSize];
	for(int i=0;i<size;i++)	//dividing whole array n 8bits blocks to get 8 binary bits
	{
		int hh=(i+1)*8;	//8=ASCII bits
		int gg=i*8;
		for(int j=hh-1;j>=gg;j--)
		{	
			binaryAr[j]=arr[i]%2;		//mod binary digit 1,0
			arr[i]=arr[i]/2;		//divide orig val
		}
	}
	//Print binary
	/*for(int i=0;i<fSize;i++)
	{
		cout<<binaryAr[i]<<" ";
	}
	cout<<endl;*/
	return binaryAr;
}
int *bintoASC(int a[],int size)
{
	//binary to ascii
	int *ASCIIAr=new int[size/8];
	//7 bit =1 ASCII value
	int Ssize=size/8;
	for(int i=0;i<Ssize;i++)
	{
		int hh=(i+1)*8;
		int gg=i*8;
		int au=0;
		int x=0;
		for(int j=hh-1;j>=gg;j--)
		{	
			x=x+a[j]*pow(2,au);
			au++;
		}
		ASCIIAr[i]=x;
	}

	return ASCIIAr;
}
char * toHEX(int dec[], int inputSize)
{
	

	//convert ascii of input to binary
	int *a=convBin(dec,inputSize);
	/*cout<<endl;
	for(int i=0;i<inputSize*8;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	//binary to hex
	int size=inputSize*8;
	int *hexaArr=new int[inputSize*2];
	
	for(int i=0;i<size/4;i++)
	{
		int hexd=0;
		int x=0;
		while (hexd<4)	//4 bin=1 hex
		{
			int hh=(i+1)*4;
			int gg=i*4;
			int au=0;
			x=0;
			for(int j=hh-1;j>=gg;j--)
			{	
				x=x+a[j]*pow(2,au);
				au++;
			}
			
			hexd++;
		}
		hexaArr[i]=x;
		
		
	}
	//print hexa
	/*for(int i=0;i<size/4;i++)
	{
		cout<<hexaArr[i]<<" ";
	}
	cout<<endl;*/
	
	char *array=new char [inputSize*2];//32];
	for(int i=0;i<inputSize*2;i++)
	{
		if(hexaArr[i]<10)
		{
			array[i]=hexaArr[i]+48;
		}
		else 
		{
			if(hexaArr[i]==10)
			{
				array[i]=65;	//A=65
			}
			else if(hexaArr[i]==11)
			{
				array[i]=66;
			}
			else if(hexaArr[i]==12)
			{
				array[i]=67;
			}
			else if(hexaArr[i]==13)
			{
				array[i]=68;
			}
			else if(hexaArr[i]==14)
			{
				array[i]=69;
			}
			else if(hexaArr[i]==15)
			{
				array[i]=70;
			}
		}
		
	}
	
	
	
	
	delete a;
	return array;
	
}
char * splitBytes(char arr[])
{
	//split by ','
	//seperating bytes in char arrays
	char *hexx=new char[47];
	//add delimiter to split
	int x=0;
	for(int i=0;i<47;i++)
	{
		if(x!=0&&(x%2==0))
		{
			hexx[i]=44;
			i++;
			
		}
		
		hexx[i]=arr[x];
		x++;
	}
	//cout<<hexx<<endl;
	return hexx;
}
char*** makeMatrix(char arr[])
{
	//sep y commas
	char *u=splitBytes(arr);
	//cout<<u<<endl;
	//store bytes in arrays
	char *a[16];	//array of bytes
	//bytes are stored as character arrays
		
	char *tok=strtok(u,",");
	int i=0;
	for(;tok;tok=strtok(NULL,","))
	{
		a[i]=tok;
		i++;
	}
	/*for(int i=0;i<16;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	
	//-----------------------------------------------
	//store in 4x4
	char *** matt=new char **[4];
	for(int i=0;i<4;i++)
	{
		matt[i]=new char*[4];
	}
	char *mat[4][4];
	int x=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			matt[j][i]=a[x];
			x++;
		}
	}
	
	//print
	/*
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
		{
			cout<<matt[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	*/
	return matt;	
}
string byteShift(char w[])	//left circular bypte shift  				//step1 galois
{
	char *nodes= splitBytes(w);	//add ',' to seperate bytes
	//seperate byptes by delimeter ','
	char *a[4];	//array of bytes
	//bytes are stored as character arrays
		
	char *tok=strtok(nodes,",");
	int i=0;
	for(;tok;tok=strtok(NULL,","))
	{
		a[i]=tok;
		i++;
	}
	
	//shift
	char *temp=a[0];
	for(int i=0;i<4-1;i++)
	{
		a[i]=a[i+1];
		
	}
	a[3]=temp;
	/*for(int i=0;i<4;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	*/
	//concatenate to a single array
	string s[4];
	for(int i=0;i<4;i++)
	{
		s[i]=a[i];
		
	}
	string c=s[0]+s[1]+s[2]+s[3];
	//cout<<c<<endl;
	return c;
	
	//cout<<a[1]+a[0]<<endl
	
	
}
string byteSubstitute(string s)//step2 galoi
{
	string s_box[16][16]=
	{"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76",			//0
	 "CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0",			//1
	 "B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15",			//2
	 "04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75",			//3
	 "09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84",			//4
	 "53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF",			//5
	 "D0","EF","AA","FB","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8",			//6
	 "51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2",			//7
	 "CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73",			//8
	 "60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB",			//9
	 "E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79",			//10
	 "E7","C8","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08",			//11
	 "BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A",			//12
 	 "70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E",			//13
 	 "E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF",			//14
 	 "8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16",			//15
	};
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
	
	
	//conv string to char array
	char *cArr=new char[8];
	for(int i=0;i<8;i++)
	{
		cArr[i]=s[i];
	}
	
	//add commas to seperate bytes
	char *aa=splitBytes(cArr);
	
	//cout<<"s\t"<<aa<<endl;
	
	//split bytes into char arrays
	char *byt[4];	//an array to hold 4 char arrays
	//each char array=1 byte
	char *tok=strtok(aa,",");
	int i=0;
	for(;tok;tok=strtok(NULL,","))
	{
		byt[i]=tok;
		i++;
	}
	/*for(int i=0;i<4;i++)
	{
		
		cout<<byt[i]<<" ";
	}
	cout<<endl;
	*/
	//substitute
	string p[4];
	for(int i=0;i<4;i++)
	{
	string bytS=byt[i];
	//cout<<bytS[0]<<"l"<<bytS[1]<<endl;
	char r=bytS[0];
	char c=bytS[1];
	//cout<<r<<"Q"<<c<<endl;
	int row,column;
	if((c!='A'&&c!='B'&&c!='C'&&c!='D'&&c!='E'&&c!='F')&&(r!='A'&&r!='B'&&r!='C'&&r!='D'&&r!='E'&&r!='F'))//hexa 0-9
	{
	
		row=r-48;
		column=c-48;
		
	}
	else	//hexa A-F
	{
	
		if((r=='A'||r=='B'||r=='C'||r=='D'||r=='E'||r=='F')&&(c!='A'&&c!='B'&&c!='C'&&c!='D'&&c!='E'&&c!='F'))//row onli
		{
			if(c!='A'&&c!='B'&&c!='C'&&c!='D'&&c!='E'&&c!='F')
			{
				column=c-48;
			}
			if(r=='A')
			{
				row=10;
			}
			else if(r=='B')
			{
				row=11;
			}
			else if(r=='C')
			{
				row=12;
			}
			else if(r=='D')
			{
				row=13;
			}
			else if(r=='E')
			{
				row=14;
			}
			else if(r=='F')
			{
				row=15;
			}
		}
		else if((c=='A'||c==66||c=='C'||c=='D'||c=='E'||c=='F')&&(r!='A'&&r!='B'&&r!='C'&&r!='D'&&r!='E'&&r!='F'))//column onli
		{
			if(r!='A'&&r!='B'&&r!='C'&&r!='D'&&r!='E'&&r!='F')
			{
				row=r-48;
			}
			if(c=='A')
			{
				column=10;
			}
			else if(c==66)
			{

				column=11;
			}
			else if(c=='C')
			{
				column=12;
			}
			else if(c=='D')
			{
				column=13;
			}
			else if(c=='E')
			{
				column=14;
			}
			else if(c=='F')
			{
				column=15;
			}
		}
		else if((r=='A'||r=='B'||r=='C'||r=='D'||r=='E'||r=='F')&&(c=='A'||c==66||c=='C'||c=='D'||c=='E'||c=='F'))//both
		{
		
			if(c=='A'||c==66||c=='C'||c=='D'||c=='E'||c=='F')
			{
			if(c=='A')
			{
				column=10;
			}
			else if(c==66)
			{

				column=11;
			}
			else if(c=='C')
			{
				column=12;
			}
			else if(c=='D')
			{
				column=13;
			}
			else if(c=='E')
			{
				column=14;
			}
			else if(c=='F')
			{
				column=15;
			}
			}
			
			if(r=='A')
			{
				row=10;
			}
			else if(r=='B')
			{
				row=11;
			}
			else if(r=='C')
			{
				row=12;
			}
			else if(r=='D')
			{
				row=13;
			}
			else if(r=='E')
			{
				row=14;
			}
			else if(r=='F')
			{
				row=15;
			}
			
			
		}
		
	}
	
	
	//cout<<row<<"r"<<column<<endl;
	p[i]=s_box[row][column];
	
	}
	string substituted=p[0]+","+p[1]+","+p[2]+","+p[3];
	//cout<<substituted<<endl;
	
	return substituted;

}
int * getRoundConst(int roundNo)	//in Binary
{
	int *RC=new int[8];
	RC[0]=0;
	RC[1]=0;
	RC[2]=0;
	RC[3]=0;
	RC[4]=0;
	RC[5]=0;
	RC[6]=0;
	RC[7]=1;
	//={0,0,0,0,0,0,0,1};
	int OneB[8]={0,0,0,1,1,0,1,1};
	int tempRN=roundNo;
	//int *RoundConst=new int[8];
	
	int size=8;
	
	while(tempRN)
	{
		for(int i=0;i<size-1;i++)
		{
			RC[i]=RC[i+1];
		
		}
		RC[size-1]=0;
		tempRN--;
		size--;
	}
	
	if(roundNo==8)
	{
		
		for(int i=0;i<8;i++)
		{
			RC[i]=RC[i]^OneB[i];
		}
	}
	else if(roundNo==9)
	{
		for(int i=0;i<8;i++)
		{
			OneB[i]=OneB[i+1];
		}
		OneB[7]=0;
		for(int i=0;i<8;i++)
		{
			RC[i]=RC[i]^OneB[i];
		}
		
	}
	
	/*for(int i=0;i<8;i++)
	{
		cout<<RC[i]<<" ";
	}
	cout<<endl;
	*/
	return RC;
}
int * hexBinary(char a[],int size)
{
	int val[size];
	for(int i=0;i<size;i++)
	{
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
			val[i]=a[i]-48;
		}
		else 
		{
			if(a[i]=='A')
			{
				val[i]=10;
			}
			else if(a[i]=='B')
			{
				val[i]=11;
			}
			else if(a[i]=='C')
			{
				val[i]=12;
			}
			else if(a[i]=='D')
			{	
				val[i]=13;
			}
			else if(a[i]=='E')
			{
				val[i]=14;
			}
			else if(a[i]=='F')
			{
				val[i]=15;
			}
		}
	}
	/*for(int i=0;i<size;i++)
	{
		cout<<val[i]<<" ";
	}
	cout<<endl;*/
	int *binRK=HexBin(val,size);
	/*for(int i=0;i<size*4;i++)
	{
		cout<<binRK[i]<<" ";
	}
	cout<<endl;*/
	return binRK;
}
string addRoundKey(string s,int round)
{
	int *RC=getRoundConst(round);
	/*char *RoundC=new char[8];
	for(int i=0;i<8;i++)
	{
		RoundC[i]=RC[i]+48;
	}
	cout<<RoundC<<endl;*/
	cout<<s<<endl;
	//add commas to seperate bytes
	char aa[sizeof(s)];//=splitBytes(cArr);
	for(int i=0;i<sizeof(s);i++)
	{
		aa[i]=s[i];
	}
	
	//cout<<"s\t"<<aa<<endl;
	
	//split bytes into char arrays
	char *byt[4];	//an array to hold 4 char arrays
	//each char array=1 byte
	char *tok=strtok(aa,",");
	int i=0;
	for(;tok;tok=strtok(NULL,","))
	{
		byt[i]=tok;
		i++;
	}
	/*for(int i=0;i<4;i++)
	{
		
		cout<<byt[i]<<" ";
	}
	cout<<endl;*/
	
	string d[3];
	int x=0;
	for(int i=1;i<4;i++)
	{
		d[x]=byt[i];
		x++;
	}
	//round const added to the birst byte
	//u dont need ascii B7->11010111 that means hex to binary
	
	int *hexa=hexBinary(byt[0],2);
	/*for(int i=0;i<8;i++)
	{
		cout<<hexa[i]<<" ";
	}
	cout<<endl;*/
	//add round key take xor
	for(int i=0;i<8;i++)
	{
		hexa[i]=hexa[i]^RC[i];
	}
	//print xored
	/*for(int i=0;i<8;i++)
	{
		cout<<hexa[i]<<" ";
	}
	cout<<endl;
	*/

	
	//now you need hex but bec ur hexa takes ascii input
	//make one ascii digit
	int *u=bintoASC(hexa,8);
	//cout<<"LL"<<*u<<endl;
	
	char *a=toHEX(u,1);
	//cout<<a[0]<<a[1]<<endl;
	string tt[2];
	tt[0]=a[0];
	tt[1]=a[1];
	string reto=tt[0]+tt[1]+","+d[0]+","+d[1]+","+d[2];
	//cout<<reto<<endl;
	return reto;
	
	
}
string galois(char wl[],int round)
{
	
	//circular shift
	cout<<wl<<endl;
	string shifted=byteShift(wl);
	cout<<"galois step 1 "<<shifted<<endl;
	string BSubstitute=byteSubstitute(shifted);
	cout<<"galois step 2 "<<BSubstitute<<endl;
	string added=addRoundKey(BSubstitute,round-1);
	cout<<"galois step 3 "<<added<<endl;	
	/*char *galoisR=new char[sizeof(added)];
	for(int i=0;i<sizeof(added);i++)
	{
		galoisR[i]=added[i];
	}*/
	return added;	
}
char ** roundKey(char *arr[],int rRound)
{
	cout<<arr[3]<<endl;
	string Gal=galois(arr[3],rRound);
	//cout<<Gal<<endl;
	Gal.erase(remove(Gal.begin(),Gal.end(),','),Gal.end());
	//cout<<Gal<<endl;
	char gal[8];
	for(int i=0;i<8;i++)
	{
		gal[i]=Gal[i];
	}
	//cout<<gal;
	//gal xor with arr[0]
	//get ASCII + binary of GAL
	
	int *binG=hexBinary(gal,8);//to be xored with arr[0] binary
	/*for(int i=0;i<4*8;i++)
	{
		cout<<binG[i]<<" ";
	}
	cout<<endl;*/
	//arr[0]
	int *binA=hexBinary(arr[0],8);//to be xored with arr[0] binary
	/*for(int i=0;i<4*8;i++)
	{
		cout<<binA[i]<<" ";
	}
	cout<<endl;*/
	
	int w4[4*8];
	for(int i=0;i<4*8;i++)
	{
		w4[i]=binA[i]^binG[i];
	}
	/*for(int i=0;i<4*8;i++)
	{
		cout<<w4[i]<<" ";
	}
	cout<<endl;*/
	//after u've xored u need
	int *u=bintoASC(w4,32);
	//cout<<"LL"<<*u<<endl;
	/*for(int i=0;i<8;i++)
	{
		cout<<u[i]<<" ";
	}*/
	
	cout<<endl;
	char *a=toHEX(u,4);
	a[8]='\0';
	//cout<<a<<endl;//print extra 2 but damnn we got first key
	
	//xor w4 with arr[1] to get w5
	int *binA1=hexBinary(arr[1],8);//to be xored with arr[0] binary
	/*for(int i=0;i<4*8;i++)
	{
		cout<<binA1[i]<<" ";
	}
	cout<<endl;*/
	
	int w5[4*8];
	for(int i=0;i<4*8;i++)
	{
		w5[i]=binA1[i]^w4[i];
	}
	/*for(int i=0;i<4*8;i++)
	{
		cout<<w5[i]<<" ";
	}*/
	
	//after u've xored u need
	int *u1=bintoASC(w5,32);
	
	/*for(int i=0;i<8;i++)
	{
		cout<<u1[i]<<" ";
	}*/
	
	cout<<endl;
	char *a1=toHEX(u1,4);
	a1[8]='\0';
	//cout<<a1<<endl;
	
	
	//xor w5 with arr[2] to get w6
	int *binA2=hexBinary(arr[2],8);//to be xored with arr[0] binary
	/*for(int i=0;i<4*8;i++)
	{
		cout<<binA2[i]<<" ";
	}
	cout<<endl;*/
	
	int w6[4*8];
	for(int i=0;i<4*8;i++)
	{
		w6[i]=binA2[i]^w5[i];
	}
	/*for(int i=0;i<4*8;i++)
	{
		cout<<w6[i]<<" ";
	}*/
	
	//after u've xored u need
	int *u2=bintoASC(w6,32);
	
	/*for(int i=0;i<8;i++)
	{
		cout<<u2[i]<<" ";
	}
	*/
	//cout<<endl;
	char *a2=toHEX(u2,4);
	a2[8]='\0';
	//cout<<a2<<endl;
	
	
	//and last but not the least
	//xor w6 with arr[3] to get w7
	int *binA3=hexBinary(arr[3],8);//to be xored with arr[0] binary
	/*for(int i=0;i<4*8;i++)
	{
		cout<<binA3[i]<<" ";
	}
	cout<<endl;*/
	
	int w7[4*8];
	for(int i=0;i<4*8;i++)
	{
		w7[i]=binA3[i]^w6[i];
	}
	/*for(int i=0;i<4*8;i++)
	{
		cout<<w7[i]<<" ";
	}*/
	
	//after u've xored u need
	int *u3=bintoASC(w7,32);
	
	/*for(int i=0;i<8;i++)
	{
		cout<<u3[i]<<" ";
	}
	
	cout<<endl;*/
	char *a3=toHEX(u3,4);
	a3[8]='\0';
	//cout<<a3<<endl;
	
	char **RK=new char*[4];
	RK[0]=a;
	RK[1]=a1;
	RK[2]=a2;
	RK[3]=a3;
	//-------------------------------------------------
	/*for(int i=0;i<4;i++)
	{
		cout<<RK[i]<<" ";
	}
	cout<<endl;*/
	return RK;
}
char **keyOperations(char key[],int round)//make it a get ftn so u pass round and it sends you the key ->ret type char **
{
	char keyD[36];
	//add delimiter to split
	int x=0;
	for(int i=0;i<36;i++)
	{
		if(i!=0&&(i==8||i==17||i==26))
		{
			keyD[i]=32;
			i++;
			
		}
		
		keyD[i]=key[x];
		x++;
	}
	//cout<<keyD<<"k\n";
	//divide it in 4 array w0->w4
	//char w0[8],w1[8],w2[8],w3[8];
	char **a=new char*[4];	//an array to hold 4 char arrays
	///a[0]=w0 -> a[3]=w3
	char *tok=strtok(keyD," ");
	int i=0;
	for(;tok;tok=strtok(NULL," "))
	{
		a[i]=tok;
		i++;
	}
	/*for(int i=0;i<4;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	//a has R0 key
	
	
	//round key1
	char **rc1=roundKey(a,1);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc1[i]<<" ";
	}
	cout<<endl;
	*/
	//round key2
	char **rc2=roundKey(rc1,2);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc2[i]<<" ";
	}
	cout<<endl;
	*/
	//round key3
	char **rc3=roundKey(rc2,3);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc3[i]<<" ";
	}
	cout<<endl;
	*/
	//round key4
	char **rc4=roundKey(rc3,4);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc4[i]<<" ";
	}
	cout<<endl;
	*/
	//round key5
	char **rc5=roundKey(rc4,5);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc5[i]<<" ";
	}
	cout<<endl;
	*/
	//round key6
	char **rc6=roundKey(rc5,6);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc6[i]<<" ";
	}
	cout<<endl;
	*/
	//round key7
	char **rc7=roundKey(rc6,7);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc7[i]<<" ";
	}
	cout<<endl;
	*/
	//round key8
	char **rc8=roundKey(rc7,8);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc8[i]<<" ";
	}
	cout<<endl;
	*/
	//round key9
	char **rc9=roundKey(rc8,9);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc9[i]<<" ";
	}
	cout<<endl;
	*/
	//round key 10
	char **rc10=roundKey(rc9,10);
	/*for(int i=0;i<4;i++)
	{
		cout<<rc10[i]<<" ";
	}
	cout<<endl;*/
	
	cout<<"The Round Keys: "<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc2[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc3[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc4[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc5[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc6[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc7[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc8[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc9[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		cout<<rc10[i]<<" ";
	}
	cout<<endl;
	
	switch(round)
	{
		case 0:
			return a;
		break;
		case 1:
			return rc1;
		break;
		case 2:
			return rc2;
		break;
		case 3:
			return rc3;
		break;
		case 4:
			return rc4;
		break;
		case 5:
			return rc5;
		break;
		case 6:
			return rc6;
		break;
		case 7:
			return rc7;
		break;
		case 8:
			return rc8;
		break;
		case 9:
			return rc9;
		break;
		case 10:
			return rc10;
		break;
		
	}
}
string manageInput(char r[],int size)	//divide text in 16-16 bytes blocks
{
	cout<<size<<endl;
	char *padded=new char[33];
	string bb;
	if(size==16||size<16)
	{
		for(int i=0;i<size*2;i++)
		{
			padded[i]=r[i];
		}
		for(int j=size*2;j<32;j++)
		{
			padded[j]='0';
		}
		
		bb=padded;
		
	}
	
	else if(size>16)
	{
		int Ssize=(size/16)+1;
		cout<<Ssize<<"blocks"<<endl;
		cout<<r<<endl;
		//char *blocks[Ssize];//=new char[Ssize];
		string blocks[Ssize];
		char a[33],a2[33];
		int x=0;
			for(int i=0;i<32;i++)
			{
				a[i]=r[i];
			}
			a[32]='\0';
			blocks[0]=a;
						
			for(int j=32;j<size*2;j++)
			{
				a2[x]=r[j];
				x++;
			}
			
			
			for(int i=x;i<32;i++)
			{	
				a2[i]='0';
			}
			a2[32]='\0';
			blocks[1]=a2;
			
		
		cout<<blocks[0]<<" "<<blocks[1]<<endl;
		bb=blocks[0]+","+blocks[1];
	}
	
	return bb;
}
void Multiply(char ***pt,char ***keyy,int roundNo, char hh[])
{
	int *bin[32];
	char *arr[16];
	int x=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			arr[x]=pt[i][j];
			x++;
		}
	}
	/*for(int i=0;i<16;i++)
	{
		cout<<arr[i]<<" ";
	}*/
	cout<<endl;
	int *ii[16];
	for(int i=0;i<16;i++)
	{
		ii[i]=hexBinary(arr[i],8);
		
	}
	for(int j=0;j<8*2;j++)
	{
			int *u=bintoASC(ii[j],8);
			char *a=toHEX(u,1);
			cout<<a<<" ";
	}
	cout<<endl;
	
	//now you need hex but bec ur hexa takes ascii input
	//make one ascii digit
	
	//cout<<"LL"<<*u<<endl;
	
	
	//cout<<a[0]<<a[1]<<endl;
	/*string tt[2];
	tt[0]=a[0];
	tt[1]=a[1];
	string reto=tt[0]+tt[1]+","+d[0]+","+d[1]+","+d[2];
	/*char ***mul;
	int *bin[16];
	int x=0;
	int ddd[16];
	x=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{	
			ddd[x]=pt[i][j];
			ddd[x+1]=pt
			x++;
		}
	}
	
	for(int i=0;i<16;i++)
	{
		
			bin[i]=HexBin(ddd[i],2);//=pt[i][j]^keyy[i][j];
			//x++;
		
	}
	for(int i=0;i<16;i++)
	{
			cout<<bin[i]<<endl;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<mul[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
}
void encryption(char ***key,char arr[], char hh[])
{
	int Ssize=(strlen(arr)/32);
	cout<<Ssize<<"kk"<<endl;
	char **RoundKeyy=keyOperations(hh,1);//generate random keys
	/*for(int i=0;i<4;i++)
	{
	cout<<RoundKeyy[i]<<endl;
	}*/
	char *a[Ssize];	//array of bytes
	//bytes are stored as character arrays
		
	char *tok=strtok(arr,",");
	int i=0;
	for(;tok;tok=strtok(NULL,","))
	{
		a[i]=tok;
		i++;
	}
	/*for(int i=0;i<Ssize;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";*/
	
	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<key[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<endl;
	cout<<"Plain text Key:"<<endl;
	//matrixes
	char ***fc1;
	char ***fc2;
	if(Ssize==2)
	{
		fc1=makeMatrix(a[0]);
		fc2=makeMatrix(a[1]);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<fc1[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<fc2[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
	else if(Ssize==1)
	{
	
		fc1=makeMatrix(a[0]);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<fc1[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	//round 0
	//by fc1 first
//	Multiply(fc1,key,0,hh);
	//plaintext,key, round, plaintext array for Round Key

}
int main()
{
	char keyC[17];	//16+1 one extra for terminating null character in char array
	cout<<"enter key 16 chars onli: "<<endl;
	
	cin.getline(keyC,17);
	
	int keyA[16];
	for(int i=0;i<16;i++)
	{
		keyA[i]=keyC[i];
	}
	cout<<"in ascii form: ";
	for(int i=0;i<16;i++)
	{
		cout<<keyA[i]<<" ";
	}
	cout<<"\n";
	
	//lets convert to hexa
	cout<<"in hexa form: ";//<<endl;
	char *h=toHEX(keyA,16);
	for(int i=0;i<32;i++)
	{
		cout<<h[i];//<<" ";
	}
	cout<<endl;
	
	//encryption

	cout<<"enter text to be encrypted:"<<endl;
	char *text=new char[100];
	//cin.getline(text,17);
	cin.getline(text,100,10);
	cout<<"l"<<strlen(text)<<endl;
	int textA[strlen(text)];//[16];
	for(int i=0;i<strlen(text)/*16*/;i++)
	{
		textA[i]=text[i];
	}
	cout<<"in ascii form: ";
	for(int i=0;i<strlen(text)/*16*/;i++)
	{
		cout<<textA[i]<<" ";
	}
	cout<<"\n";
	
	//lets convert to hexa
	cout<<"in hexa form: ";//<<endl;
	char *e=toHEX(textA,strlen(text));//16
	for(int i=0;i<strlen(text)*2;i++)
	{
		cout<<e[i];//<<" ";
	}
	cout<<endl;
	//seperate bytes by comma
	string inp=manageInput(e,strlen(text));
	int lenn=0;
	for(int i=0;inp[i]!='\0';i++)
	{
		lenn++;
	}	
	cout<<lenn<<endl;
	char *arr=new char[lenn];
	for(int i=0;i<lenn;i++)
	{
		arr[i]=inp[i];
	}
	cout<<arr<<endl;
	
	//arr has the hexa seperated by comma of pt
	//time to do encryption
	
	cout<<"\n\nKey for R0"<<endl;
	char ***mm=makeMatrix(h);//R0 key
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<mm[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	encryption(mm,arr,h);
	
	//delete fc;
	delete mm;
	
	delete h;
	delete e;
	return 0;		
}
