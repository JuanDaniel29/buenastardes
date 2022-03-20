#include <iostream>
using namespace std;
#define RESET "\033[0m"
#define BLUE "\033[34m" /*blue*/
#define RED "\033[31m" /*red*/
#define GREEN "\033[32m" /*green*/

class tiempo{
	
	protected:
	
	int minutos;
	int segundos;
	
	public:
	
	tiempo ();
	~tiempo();
	int getMinutos ();
	void setMinutos (int nuevos_min);
	int getSegundos();
	void setSegundos (int nuevos_seg);
};
	
tiempo::tiempo () {
	cout << RED << "Invocando al constructor de tiempo" << RESET << endl;
	minutos = 0;
	minutos = 0;
}
tiempo::~tiempo() {
	cout << RED << "Invocando al destructor de tiempo" << RESET << endl;
	minutos = 0;
	minutos = 0;
}
int tiempo::getMinutos (){
	return this->minutos;
}
void tiempo:: setMinutos (int nuevos_min) {
	this->minutos = nuevos_min;
}
int tiempo::getSegundos (){
	return this->segundos;
}
void tiempo::setSegundos (int nuevos_seg) {
	this->segundos = nuevos_seg;
}

class artista{
	
	protected:
	
	unsigned int id;
	string nombre;
	
	public:
	
	artista ();
	~artista ();
	unsigned int getId ();
	void setId (unsigned int nueva_id);
	string getnombre ();
	void setNombre (string nuevo_nombre);	
};
artista::artista () {
	cout << RED << "Invocando al constructor de artista" << RESET << endl;
	this->id = 0;
}
artista::~artista() {
	cout << RED << "Invocando al destructor de artista" << RESET << endl;
	this->id = 0;
}
unsigned int artista:: getId () {
	return this->id;
}
void artista::setId (unsigned int nueva_id){
	this->id = nueva_id;
}
string artista::getnombre (){
	return this->nombre;
}
void artista::setNombre (string nuevo_nombre){
	this->nombre = nuevo_nombre;
}
class usuario{
	
	protected:
	
	bool activado;
	unsigned int id;
	string login;
	string password;
	
	public:
	
	usuario();
	~usuario();
	void setActivado ();
	unsigned int getId();
	void setId (unsigned int nueva_id);
	string getLogin ();
	void setLogin (string nuevo_login);	
	string getPassword ();
	void setPassword (string nuevo_password);
};
usuario::usuario(){
	cout << RED << "Invocando al constructor de usuario" << RESET << endl;
	this->activado = true;
	this->id = 0;
}
usuario::~usuario() {
	cout << RED << "Invocando al destructor de usuario" << RESET << endl;
	this->setActivado ();
	this->id = 0;
}
void usuario::setActivado (){
	this->activado = false;
}
unsigned int usuario:: getId () {
	return this->id;
}
void usuario::setId (unsigned int nueva_id){
	this->id = nueva_id;
}
string usuario::getLogin (){
	return this->login;
}
void usuario::setLogin (string nuevo_login){
	this->login = nuevo_login;
}
string usuario::getPassword (){
	return this->password;
}
void usuario::setPassword (string nuevo_password){
	this->password = nuevo_password;
}
class cancion {
	
	protected:
	
	unsigned int id;
	string titulo;
	artista *artistas;
	int util_artista;
	tiempo duracion;
	int total_reproducciones;
	
	public:
	cancion();
	~cancion();
	unsigned int getId();
	void setId ( unsigned int nuevo_id);
	string getTitulo ();
	void setTitulo (string nuevo_titulo);
	int getUtilArtista ();
	void setUtilArtista (int nueva_util);
	int getTotalReproducciones ();
	void setTotalReproducciones (int nuevo_total);
	void introducirTiempoCancion(int minutos, int segundos);
	void introducirArtista (unsigned int id, string nombre);
	void imprimirTiempo ();
	void imprimirArtistas();
	//void imprimirArtista();
};
cancion::cancion (){
	cout << RED << "Invocando al constructor de cancion" << RESET << endl;
	this->artistas = new artista[5];
	this->util_artista = 5;
}
cancion::~cancion(){
	cout << RED << "Invocando al destructor de cancion" << RESET << endl;
	delete[] this->artistas;
	this->util_artista = 0;
}
unsigned int cancion:: getId() {
	return this->id;
}
void cancion:: setId ( unsigned int nuevo_id) {
	this->id = nuevo_id;
}
string cancion:: getTitulo (){
	return this->titulo;
}
void cancion:: setTitulo (string nuevo_titulo){
	this->titulo = nuevo_titulo;
}
int cancion:: getUtilArtista (){
	return this->util_artista;
}
void cancion:: setUtilArtista (int nueva_util){
	this->util_artista = nueva_util;
}
int cancion:: getTotalReproducciones (){
	return this->total_reproducciones;
}
void cancion:: setTotalReproducciones (int nuevo_total){
	this->total_reproducciones = nuevo_total;
}
void cancion::introducirTiempoCancion(int minutos, int segundos) {
	this->duracion.setMinutos (minutos);
	this->duracion.setSegundos (segundos);
	
	//cout << this->duracion.getMinutos() << ":" << this->duracion.getSegundos () << endl;
}
void cancion::introducirArtista (unsigned int id, string nombre){
	this->artistas->setId (id);
	this->artistas->setNombre(nombre);
}
void cancion::imprimirTiempo (){
	
	cout << GREEN << "Duracion: " << RESET << this->duracion.getMinutos() << ":" << this->duracion.getSegundos () << endl;
	
}
void cancion:: imprimirArtistas (){
	
		cout << GREEN << "Artista: " << RESET << endl;
		cout << GREEN <<"Id: " << RESET <<  this->artistas->getId()<< endl;
		cout << GREEN <<"Nombre: " << RESET <<  this->artistas->getnombre() << endl;
}
void ordenar(cancion** c) {
	
	cancion *aux;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (c[j]->getTotalReproducciones () < c[j - 1]->getTotalReproducciones ()) {
				aux = c[j];
				c[j] = c[j - 1];
				c[j - 1] = aux;
			}
		}
	}
}
class playlist {
	
	protected:
	
	unsigned int id;
	string nombre;
	cancion **canciones_playlist;
	int util_v_canciones;
	tiempo duracion_total;
	
	public:
	
	playlist();
	~playlist();
	unsigned int getId();
	void setId ( unsigned int nuevo_id);
	string getnombre ();
	void setNombre (string nuevo_nombre);
	int getUtil ();
	void setUtil (int nueva_util);
	void introducirDuracion (int minutos, int segundos);
	
};
playlist::playlist (){
	cout << RED << "Invocando al constructor de playlist" << RESET << endl;
	this->id = 0;
	util_v_canciones = 5;
	canciones_playlist = new cancion* [5];
}
playlist::~playlist (){
	cout << RED << "Invocando al destructor de playlist" << RESET << endl;
	this->id = 0;
	util_v_canciones = 0;
	for (int i = 0; util_v_canciones; i++) {
		delete canciones_playlist[i];
	}
	delete canciones_playlist;
	canciones_playlist = 0;
}
unsigned int playlist:: getId() {
	return this->id;
}
void playlist:: setId ( unsigned int nuevo_id) {
	this->id = nuevo_id;
}
string playlist::getnombre (){
	return this->nombre;
}
void playlist::setNombre (string nuevo_nombre){
	this->nombre = nuevo_nombre;
}
int playlist::getUtil(){
	return this->util_v_canciones;
}
void playlist::setUtil(int nueva_util) {
	this->util_v_canciones = nueva_util;
}
class vista{
	
	protected:
	
	usuario **usuarios_sistema;
	int util_usuarios_sistema;
	cancion **canciones_sistema;
	int util_canciones_sistema;
	artista **artistas_sistema;
	int util_artistas_sistema;
	
	public:
	
	vista();
	~vista();
	int getUtilUsuarios();
	void setUtilUsuarios(int nueva_util);
	int getUtilCanciones();
	void setUtilCanciones(int nueva_util);
	int getUtilArtistas();
	void setUtilArtistas(int nueva_util);
	void menuSistema ();
	void inicializar();
	//cancion copiarCancion(cancion** c);
	void ordenar();
};
vista::vista(){
	cout << RED << "Invocando al constructor de vista" << RESET << endl;
	this->usuarios_sistema = new usuario* [5];
	this->util_usuarios_sistema = 5;
	this->canciones_sistema = new cancion* [5];
	this->util_canciones_sistema = 5;
	this->artistas_sistema = new artista* [5];
	this->util_artistas_sistema = 5;	
}
vista::~vista(){
	cout << RED << "Invocando al destructor de vista" << RESET << endl;
	for (int i = 0; i < util_usuarios_sistema; i++) {
		delete usuarios_sistema[i];
	}
	delete [] usuarios_sistema;
	this->util_usuarios_sistema = 0;
	
	for (int i = 0; i < util_canciones_sistema; i++) {
		delete canciones_sistema[i];
	}
	delete [] canciones_sistema;
	this->util_usuarios_sistema = 0;
	
	for (int i = 0; i < util_artistas_sistema; i++) {
		delete artistas_sistema[i];
	}
	delete [] artistas_sistema;
	this->util_artistas_sistema = 0;
}
int vista::getUtilUsuarios(){
	return this->util_usuarios_sistema;
}
void vista::setUtilUsuarios(int nueva_util){
	this->util_usuarios_sistema = nueva_util;
}
int vista::getUtilCanciones(){
	return this->util_canciones_sistema;
}
void vista::setUtilCanciones(int nueva_util){
	this->util_canciones_sistema = nueva_util;
}
int vista::getUtilArtistas(){
	return this->util_artistas_sistema;
}
void vista::setUtilArtistas(int nueva_util){
	this->util_artistas_sistema = nueva_util;
}
void vista::inicializar(){
	cout << RED << "Llamando a inicializar" << RESET << endl;
	usuario *u;
	u = new usuario;
	string a = "Hola", b = "josegras";
	u->setLogin(a);
	u->setPassword(b);
	this->usuarios_sistema[0] = u;
	u = 0;
	
	cancion *c, *c1, *c2;
	c = new cancion;
	c1 = new cancion;
	c2 = new cancion;
	
	unsigned int id_cancion = 123, id_artista = 321;
	string titulo = "Cansion";
	string nombre = "Nombre";
	int reproducciones = 20;
	int minutos = 3, segundos = 12;
	/**
	this->canciones_sistema[0]->setId(id_cancion);
	this->canciones_sistema[0]->setTitulo(titulo);
	this->canciones_sistema[0]->introducirArtista (id_artista, nombre);
	this->canciones_sistema[0]->setTotalReproducciones (reproducciones);
	this->canciones_sistema[0]->introducirTiempoCancion (minutos, segundos);
	*/
	c->setId(id_cancion);
	c->setTitulo(titulo);
	c->introducirArtista (id_artista, nombre);
	c->setTotalReproducciones (reproducciones);
	c->introducirTiempoCancion (minutos, segundos);
	this->canciones_sistema[0] = c;

	c1->setId(321);
	c1->setTitulo("Cansion2");
	c1->introducirArtista (id_artista, nombre);
	c1->setTotalReproducciones (52);
	c1->introducirTiempoCancion (2, 21);
	this->canciones_sistema[1] = c1;
	
	c2->setId(231);
	c2->setTitulo("Cansion3");
	c2->introducirArtista (id_artista, nombre);
	c2->setTotalReproducciones (2);
	c2->introducirTiempoCancion (1, 10);
	this->canciones_sistema[2] = c2;
	
	this->util_canciones_sistema = 3;
	//cout << this->canciones_sistema[0]->getTitulo() << endl;	
	//cout << this->canciones_sistema[0]->getId() << endl;
	//this->canciones_sistema[0]->imprimirTiempo();
	c = 0;
	c1 = 0;
	c2 = 0;
	//delete c;
	//delete c1;
	//delete c2;
}
/**cancion vista::copiarCancion(cancion **c) {
	cout << RED << "Iniciando copia" << RESET << endl;
	
	for (int i = 0; i < this->util_canciones_sistema; i++) {
		
		c[i] = this->canciones_sistema[i];
	}
	return c;
}*/
void vista::ordenar(){
	
	cout << RED << "Iniciando ordenar" << RESET << endl;
	cancion *aux;
	aux = new cancion;
	for (int i = 0; i < this->util_canciones_sistema; i++) {
		for (int j = this->util_canciones_sistema - 1; j > i; j--) {
			if (this->canciones_sistema[j]->getTotalReproducciones() > this->canciones_sistema[j - 1]->getTotalReproducciones ()) {
				aux = this->canciones_sistema[j];
				this->canciones_sistema[j] = this->canciones_sistema[j - 1];
				this->canciones_sistema[j - 1] = aux;
			}
			//cout << this->canciones_sistema[j]->getTotalReproducciones() << endl;
		}
	}
	delete aux;
}	
void vista::menuSistema (){
	//cout << this->usuarios_sistema[0]->getLogin() << endl;
	//cout << this->usuarios_sistema[0]->getPassword() << endl;
	 int tecla = 0;
	 
	 do{
		 cout << BLUE << "¿Que quiere hacer?" << RESET << endl;
		 cout << BLUE << "1) Login" << RESET << endl;
		 cout << BLUE << "2) Generar datos del sistema"<< RESET << endl;
		 cout << BLUE << "3) Imprimir datos generales" << RESET << endl;
		 cout << BLUE <<"4) Rankings " << RESET << endl;
		 cout << BLUE << "5) Salir " << RESET; cin >> tecla;
		 
		 switch (tecla) {
		 	
		 	case 1:
		 		/**string login;
				string password;
				bool login1 = false;
				cout << "Introduce el login: "; cin >> login;
				cout << "Introduce la contraseña: ";cin >> password; 
				
				/**if (login == this->usuarios_sistema[0]->getLogin() && password ==  this->usuarios_sistema[0]->getPassword()){
					cout << "HOLA BUENOS DIAS" << endl;
				}
				*/
				/**for (int i = 0; i < this->util_usuarios_sistema && login1 == false; i++) {
					
					if (login == this->usuarios_sistema[i]->getLogin() && password ==  this->usuarios_sistema[i]->getPassword()) {
						login1 = true;
					}
				}
				if (login1 == true) {
				cout << "HOLA" << endl;
				}*/	
			break;
			case 2: 
			
				this->inicializar();
				
			break;
			case 3:
				
				//cout << this->canciones_sistema[0]->getTitulo() << endl;
				//cout << this->usuarios_sistema[0]->getLogin() << endl;
				cout << "\n";
				cout << GREEN << "login: "<< RESET << this->usuarios_sistema[0]->getLogin() << endl;
				cout << GREEN << "password: "<< RESET << this->usuarios_sistema[0]->getPassword() << endl;
				cout << GREEN << "-----------------------------------------------------------" << RESET << endl;
				cout << "\n";
				
				cout <<  GREEN << "Canciones: " << RESET << endl;
				for (int i = 0; i < this->util_canciones_sistema; i++) {
					cout << GREEN << "cancion: " << i+1 << RESET << endl;
					cout << GREEN << "Id: "<< RESET << this->canciones_sistema[i]->getId() << endl;
					cout << GREEN <<"Titulo: " << RESET << this->canciones_sistema[i]->getTitulo() << endl;
					cout << GREEN << "Total Reproducciones: "<< RESET << this->canciones_sistema[i]->getTotalReproducciones() << endl;
					this->canciones_sistema[i]->imprimirTiempo();
					this->canciones_sistema[i]->imprimirArtistas();
					cout << "\n";
				}
			break;
			case 4:
				int tecla2 = 0;
				
				cout << "\n";
				cout << BLUE << "¿Cuales son tus criterios de busqueda?" << RESET << endl;
				cout << BLUE << "Top 3 general" << RESET << endl;
				cout << BLUE << "Top 3 por tipo de cancion" << RESET << endl;
				cout << BLUE << "Top artistas " << RESET; cin >> tecla2;
				
				switch (tecla2) {
					
					case 1:
					
						/**cancion **aux;
						
						aux = this->copiarCancion(aux);
						ordenar (aux);
						
						cout << "Canciones: " << endl;
						for (int i = 0; i < 3; i++) {
							cout << "Id: " << aux[i]->getId() << endl;
							cout << "Titulo: " << aux[i]->getTitulo() << endl;
							cout << "Total Reproducciones: " << aux[i]->getTotalReproducciones() << endl;
							aux[i]->imprimirTiempo();
						}
						
						delete [] aux;*/
						this->ordenar();
						cout << "Canciones: " << endl;
						for (int i = 0; i < 3; i++) {
							cout << "Id: " << this->canciones_sistema[i]->getId() << endl;
							cout << "Titulo: " << this->canciones_sistema[i]->getTitulo() << endl;
							cout << "Total Reproducciones: " << this->canciones_sistema[i]->getTotalReproducciones() << endl;
							this->canciones_sistema[i]->imprimirTiempo();
						}
					break;				
				}
			break;			 		
		 }
		 if (tecla == 5) {
		 	cout << RED << "Programa finalizado" << RESET << endl;
		 }
	}while(tecla != 5); 
}
int main (){
	
	
	/**cancion c;
	//c.introducirTiempoCancion(3, 12);
	cancion *pun;

	pun = &c;
	
	pun->setId (1);
	cout << pun->getId () << endl;
	*/
	vista v;
	//v.inicializar();
	v.menuSistema ();
		
}

