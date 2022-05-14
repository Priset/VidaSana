#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define INF 100000010;
using namespace std;    
int precio[] = {8, 8, 10, 15, 25, 30, 35, 35, 45, 80}; //1.linaza, 2.te_verde, 3.quinua, 4.palta, 5.yogurt_griego, 6.huevo, 7.avena, 8.frutos secos, 9.pollo, 10.pescado.
int gananciaProteinas[] = {1, 25, 40, 50, 200, 360, 390, 400, 540, 840};
int gananciaCalorias[] = {40, 980, 1400, 2250, 3200, 3600, 3600, 3900, 6600, 10600};
int gananciaCarbohidratos[] = {1, 2, 3, 15, 140, 180, 300, 500, 530, 600};
int nroProductos = 10;

int dp1[100][10000]; 
int dp2[100][10000];
int dp3[100][10000];
int dp4[100][10000];

int subirMasaMuscularTD(int i, int dineroUsuario){  
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp1[i][dineroUsuario] == -1) {
        dp1[i][dineroUsuario] =  max(gananciaProteinas[i] + subirMasaMuscularTD(i+1,dineroUsuario-precio[i]), subirMasaMuscularTD(i+1,dineroUsuario));
    }
    
    return dp1[i][dineroUsuario];

}

int aumentarVolumenTD(int i, int dineroUsuario){
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp2[i][dineroUsuario] == -1) {
        dp2[i][dineroUsuario] =  max(gananciaCalorias[i] + aumentarVolumenTD(i+1,dineroUsuario-precio[i]), aumentarVolumenTD(i+1,dineroUsuario));
    }
    
    return dp2[i][dineroUsuario];
}

int subirPesoTD(int i, int dineroUsuario){
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp3[i][dineroUsuario] == -1) {
        dp3[i][dineroUsuario] =  max(gananciaCarbohidratos[i] + subirPesoTD(i+1,dineroUsuario-precio[i]), subirPesoTD(i+1,dineroUsuario));
    }
    
    return dp3[i][dineroUsuario];

}

int minimoProductos(int dineroUsuario) {  
    memset(dp4,0,sizeof (dp4));
    for(int i = 1; i <= dineroUsuario ;i++) {
        dp4[0][i] = INF;
    }

    for (int i = 1 ;i <= sizeof(precio)/sizeof(precio[0]); i++ ) {
        for(int j = 0; j <= dineroUsuario ; j++ ){
            if(j- precio [i-1]>=0) {
                int valor = 1 + dp4[i][j-precio[i-1]];
                dp4[i][j] = min (valor, dp4[i-1][j]);
            }
            else {
                dp4[i][j] = dp4[i-1][j];
            }
        }
    }
    
    return dp4[sizeof(precio)/sizeof(precio[0])][dineroUsuario];
}

void showMenu(){
    cout<<"🔱🔱🔱🔱🔱🔱🔱🔱🔱🔱VIDA-SANA🔱🔱🔱🔱🔱🔱🔱🔱🔱🔱🔱🔱"<<endl;
    cout<<"1️⃣ Ejecutar el Primer Ejemplo para subir masa muscular. 💪🏻"<<endl;
    cout<<"2️⃣ Ejecutar el Segundo Ejemplo para subir masa muscular. 🦵🏻"<<endl;
    cout<<"3️⃣ Ejecutar el Primer Ejemplo para aumentar volumen. 🏋️‍♀️"<<endl;
    cout<<"4️⃣ Ejecutar el Segundo Ejemplo para aumentar volumen. 🏃‍♂️"<<endl;
    cout<<"5️⃣ Ejecutar el Primer Ejemplo para subir de peso. 🍗"<<endl;
    cout<<"6️⃣ Ejecutar el Segundo Ejemplo para subir de peso. 🥩"<<endl;
    cout<<"7️⃣ Salir del programa. 🍻"<<endl;
    cout<<"💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳💳"<<endl;
}

void example1(){
    int dineroUsuario = 150;
    cout<<"Ejecutando el Primer Ejemplo para subir masa muscular 💪🏻 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de proteinas que se puede obtener con " << dineroUsuario << "bs es " << subirMasaMuscularTD(0,dineroUsuario) << " proteinas." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

void example2(){
    int dineroUsuario = 100;
    cout<<"Ejecutando el Segundo Ejemplo para subir masa muscular 🦵🏻 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de proteinas que se puede obtener con " << dineroUsuario << "bs es " << subirMasaMuscularTD(0,dineroUsuario) << " proteinas." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

void example3(){
    int dineroUsuario = 130;
    cout<<"Ejecutando el Primer Ejemplo para aumentar volumen 🏋️‍♀️ ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de calorias que se puede obtener con " << dineroUsuario << "bs es " << aumentarVolumenTD(0,dineroUsuario) << " calorias." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

void example4(){
    int dineroUsuario = 70;
    cout<<"Ejecutando el Segundo Ejemplo para aumentar volumen 🏃‍♂️ ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de calorias que se puede obtener con " << dineroUsuario << "bs es " << aumentarVolumenTD(0,dineroUsuario) << " calorias." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

;void example5(){
    int dineroUsuario = 90;
    cout<<"Ejecutando el Primer Ejemplo para subir de peso 🍗 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de carbohidratos que se puede obtener con " << dineroUsuario << "bs es " << subirPesoTD(0,dineroUsuario) << " carbohidratos." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

void example6(){
    int dineroUsuario = 190;
    cout<<"Ejecutando el Segundo Ejemplo para subir de peso 🥩 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de carbohidratos que se puede obtener con " << dineroUsuario << "bs es " << subirPesoTD(0,dineroUsuario) << " carbohidratos." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " producto/s con " << dineroUsuario << "bs." << endl;
}

void exit(){
    cout<<"Saliendo del programa... 🍺"<<endl;
}

int main(){
    input;
    int option;
    cin>>option;
    showMenu();
    do{
        memset(dp1, -1,sizeof (dp1));
        memset(dp2, -1,sizeof (dp2));
        memset(dp3, -1,sizeof (dp3));
        switch (option) {
        case 1:
            example1();
            break;
        case 2:
            example2();
            break;
        case 3:
            example3();
            break;
        case 4:
            example4();
            break;
        case 5:
            example5();
            break;
        case 6:
            example6();
            break;
        case 7:
            exit();    
            break;     
        default:
            cout<<"ERROR!⚠️ No existe esa opción."<<endl;
        }
    } while (cin>>option && option);
}



