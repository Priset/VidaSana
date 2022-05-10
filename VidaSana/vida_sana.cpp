#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define INF 100000010;
using namespace std;
int precio[] = {45, 30, 80, 35, 8, 10, 8, 25, 15, 35};  //1.pollo, 2.huevo, 3.pescado, 4.avena, 5.linasa, 6.quinua, 7.te_verde, 8.yogurt_griego, 9.palta, 10.frutos secos
int gananciaProteinas[] = {540, 390, 400, 25, 360, 200, 1, 50, 40, 840}; 
int gananciaCalorias[] = {6600, 2250, 3600, 3900, 10600, 3600, 40, 1400, 3200, 980};
int gananciaCarbohidratos[] = {}; //Escribir carbohidratos
int nroProductos = 10;

int dp[100][100000];

int subirMasaMuscularTD(int i, int dineroUsuario){  //NO CALUCA VALORES MENORES A 45 :C
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp[i][dineroUsuario] == -1) {
        dp[i][dineroUsuario] =  max(gananciaProteinas[i] + subirMasaMuscularTD(i+1,dineroUsuario-precio[i]), subirMasaMuscularTD(i+1,dineroUsuario));
    }
    
    return dp[i][dineroUsuario];

}

int aumentarVolumenTD(int i, int dineroUsuario){
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp[i][dineroUsuario] == -1) {
        dp[i][dineroUsuario] =  max(gananciaCalorias[i] + aumentarVolumenTD(i+1,dineroUsuario-precio[i]), aumentarVolumenTD(i+1,dineroUsuario));
    }
    
    return dp[i][dineroUsuario];

}

int subirPesoTD(int i, int dineroUsuario){
    if(dineroUsuario-precio[i] < 0){
        return 0;
    }

    if(i >= nroProductos){
        return 0;
    }

    if(dp[i][dineroUsuario] == -1) {
        dp[i][dineroUsuario] =  max(gananciaCarbohidratos[i] + subirPesoTD(i+1,dineroUsuario-precio[i]), subirPesoTD(i+1,dineroUsuario));
    }
    
    return dp[i][dineroUsuario];

}


/*
int bajarPesoTD(int i, int dineroUsuario){   // REDUCE HASTA NUMEROS NEGATIVOS Y ENTRA AL IF POR LO TANTO VUELVE EL INF
    for(int i = 1; i <= dineroUsuario ;i++) {
        dp[0][i] = 2000;                       //PUEDE ESTAR MAL EL DP??
    }
    cout<<dineroUsuario-precio[i]<<endl;
    if(dineroUsuario-precio[i] < 0){
        cout<<"SORO"<<endl;
        return 2000; 
    }

    if(i >= nroProductos){
        return 2000; 
    }

    if(dp[i][dineroUsuario] == 2000) {
        dp[i][dineroUsuario] =  min(gananciaProteinas[i] + bajarPesoTD(i+1,dineroUsuario-precio[i]), bajarPesoTD(i+1,dineroUsuario));   //ESTA MAL EL LLAMADO RECURSIVO??
    }
    
    return dp[i][dineroUsuario];
}
*/

/*
int definicionTD(int i, int dineroUsuario){ 
    if(dineroUsuario-precio[i] < 0){
        return INF; // 0 ?
    }

    if(i >= nroProductos){
        return INF;
    }

    if(dp[i][dineroUsuario] == -1) {
        dp[i][dineroUsuario] = min(gananciaCalorias[i] + definicionTD(i+1,dineroUsuario-precio[i]), definicionTD(i+1,dineroUsuario));
    }
    
    return dp[i][dineroUsuario];

}
*/


int minimoProductos(int dineroUsuario) {  //MINIMO DE PRODUCTOS QUE SE PUEDEN COMPRAR????? CON EL DINERO??
    //int dp2[value5][100];
    memset(dp,0,sizeof (dp));
    for(int i = 1; i <= dineroUsuario ;i++) {
        dp[0][i] = INF;
    }

    for (int i = 1 ;i <= sizeof(precio)/sizeof(precio[0]); i++ ) {
        for(int j = 0; j <= dineroUsuario ; j++ ){
            if(j- precio [i-1]>=0) {
                int valor = 1 + dp[i][j-precio[i-1]];
                dp[i][j] = min (valor, dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[sizeof(precio)/sizeof(precio[0])][dineroUsuario];
}


void showMenu(){
    //cout << "\033[1;31mbold red text\033[0m\n"; //NECESITO TPONER COLOR
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
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
}

void example2(){
    int dineroUsuario = 100;
    cout<<"Ejecutando el Segundo Ejemplo para subir masa muscular 🦵🏻 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de proteinas que se puede obtener con " << dineroUsuario << "bs es " << subirMasaMuscularTD(0,dineroUsuario) << " proteinas." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
}

void example3(){
    int dineroUsuario = 130;
    cout<<"Ejecutando el Primer Ejemplo para aumentar volumen 🏋️‍♀️ ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de calorias que se puede obtener con " << dineroUsuario << "bs es " << aumentarVolumenTD(0,dineroUsuario) << " calorias." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
}

void example4(){
    int dineroUsuario = 70;
    cout<<"Ejecutando el Segundo Ejemplo para aumentar volumen 🏃‍♂️ ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de calorias que se puede obtener con " << dineroUsuario << "bs es " << aumentarVolumenTD(0,dineroUsuario) << " calorias." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
}

;void example5(){
    int dineroUsuario = 90;
    cout<<"Ejecutando el Primer Ejemplo para subir de peso 🍗 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de carbohidratos que se puede obtener con " << dineroUsuario << "bs es " << subirPesoTD(0,dineroUsuario) << " carbohidratos." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
}

void example6(){
    int dineroUsuario = 190;
    cout<<"Ejecutando el Segundo Ejemplo para subir de peso 🥩 ..."<<endl;
    cout<<"⤵️"<<endl;
    cout<<"El maximo de carbohidratos que se puede obtener con " << dineroUsuario << "bs es " << subirPesoTD(0,dineroUsuario) << " carbohidratos." << endl;
    cout<<"Se puede comprar minimo " << minimoProductos(dineroUsuario) << " productos con " << dineroUsuario << "bs." << endl;
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
        memset(dp, -1,sizeof (dp));
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


