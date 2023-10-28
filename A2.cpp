#include <iostream> 
#include<math.h>


using namespace std;
class Xemay{
    private:
        char maxe;
        char tenxe[100];
        char hangxe[100];
        int dungtichxilanh;
    public:
        void nhap(){
            cin.ignore();
            cout << "nhap ma xe"<<endl;
            cin>>maxe;
            fflush(stdin);
            cin.ignore();
			cout << "nhap ten xe "<<endl;
            cin.getline(tenxe,100);
            fflush(stdin);
            cin.ignore();
            cout<< "Nhap hang xe "<<endl;
            cin.getline(hangxe,100);
            fflush(stdin);
            cin.ignore();
			cout<< "nhap dung tich xi lanh"<<endl;
            cin>>dungtichxilanh;
            fflush(stdin);
            
        };
        void xuat(){
            cout<<"ma xe la = "<<maxe<<endl;
            cout<<"ten xe la = "<<tenxe<<endl;
            cout<<"hang xe la = "<<hangxe<<endl;
            cout<<"dung tich xi lanh"<<dungtichxilanh<<endl;
        };
        int laydungtichxilanh(){
            return dungtichxilanh;
        };
        char laymaxe(){
        	return maxe;
		}
};
void nhapnxe(Xemay a[],int *n){
     do{
        		cout<<"nhap so luong xe muon nhap ( 0>n>200)"<<endl;
        		cin>>*n;
    	}while(*n<0 || *n>200 );
	for(int i=0;i<*n;i++){
        a[i].nhap();
        system ("pause");
    }
}
void innxe(Xemay a[],int n){
    for(int i=0;i<n;i++){
       cout<<"Xe may thu : "<<i<<endl;
	    a[i].xuat();
	    system ("pause");
    }
}
void sapxep(Xemay a[],int n){
    Xemay tg;
    int i,j;
    //thuat toan sap xep xe theo dung tich xi lanh
	for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i].laydungtichxilanh() > a[j].laydungtichxilanh()){
                tg = a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    }
    cout<<"DANH SACH SAU KHI SAP XEP LA"<<endl;
    innxe(a,n);
    
    
}
void xoaxe(Xemay a[],int n){
    //vi tri can xoa trong mang
    int vitrixoa;
    //hien thi mang ban dau
    cout<<"DANH SACH BAN DAU"<<endl;
    innxe(a,n);
    cout<<"Nhap vi tri xoa "<<endl;
    cin>>vitrixoa;
    // Dich chuyen mang ve ben trai tu vi tri xoa
    if(vitrixoa>=0 && vitrixoa<=n){
	
	for(int i = vitrixoa; i < n - 1; i++){
        a[i] = a[i+1];
    };
    //sau khi xoa giam so luong phan tu mang
    n--;
	cout<<"DA XOA THANH CONG"<<endl; 
    cout<<"DANH SACH SAU KHI XOA "<<endl;
    innxe(a,n);} else{
	 cout<<"vi tri xoa khong hop le"<<endl;
	}
}


void chenxe(Xemay a[],int n){
    //vi tri can chen trong mang
 	Xemay b[200];
    int vitrichen,i;
    //hien thi mang ban dau
    cout<<"DANH SACH BAN DAU"<<endl;
	innxe(a,n);
    cout<<"Nhap vi tri chen "<<endl;
    cin>>vitrichen;
    if(vitrichen>=0 && vitrichen<=n){
	// Dich chuyen mang ve ben trai tu vi tri chen
	for(i = vitrichen; i < n - 1; i++){
        a[i] = a[i+1];
        a[i].nhap();
    };
    //sau khi xoa giam so luong phan tu mang
	cout<<" DA CHEN THANH CONG"<<endl; 
    cout<<"DANH SACH SAU KHI CHEN  "<<endl;
    innxe(a,n);
    }
}
void timkiem(Xemay a[],int n){
	char timmaxe;
	int i;
	cout<<"Nhap ma xe can tim"<<endl;
	cin>>timmaxe;
	for( i=0;i<n;i++){
		if(timmaxe==a[i].laymaxe()){
			cout<<"Thong tin xe :"<<endl; ;
			a[i].xuat();
		}
	}
	
}
	
	
 
int main ()
{
	Xemay b[200];
	int n;
	int luachon;
	do{
		cout<<"____________MENU_________"<<endl;
  		cout<<"1.nhap danh sach thong tin cac xe"<<endl;
   		cout<<"2.in thong tin cac xe"<<endl;
   		cout<<"3.sap xep thong in cac xe dua theo dung tich xilanh"<<endl;
   		cout<<"4.Xoa thong tin xe"<<endl;
    	cout<<"5.Chen thong tin xe"<<endl;
		cout<<"6.Tim kiem bang ma xe"<<endl;
		cout<<"7.Thoat!!!"<<endl;
		cout << "Moi chon menu: ";
		cin>>luachon;
		 switch(luachon){
       	case 0: 
       		break;
	     case 1:{
			nhapnxe(b,&n);
        	break;;
        }
		case 2:{
			innxe(b,n);
            break;
        }
        case 3:{
			sapxep(b,n);
            break;
        } 
        case 4:{
			xoaxe(b,n);
			
			break;
		}
		case 5:{
			chenxe(b,n);
			break;
		}
		case 6:{
			timkiem(b,n);
			break;
		}
		case 7:{
			break;
		}
		default:{
			cout<<"Vui long chon lai";
			break;
		}
 	}
	}while(true);
	return 0;
}
	
    
	
        
    
    

