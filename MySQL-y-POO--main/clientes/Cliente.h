#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"



using namespace std;

class Cliente : Persona {
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	}

void setNit(string n) { nit = n; }
void setNombres(string nom) { nombres = nom; }
void setApellidos(string ape) { apellidos = ape; }
void setDireccion(string dir) { direccion = dir; }
void setTelefono(int tel) { telefono = tel; }
void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
//get (mostrar)
string getNit() { return nit; }
string getNombres() { return nombres; }
string getApellidos() { return apellidos; }
string getDireccion() { return direccion; }
int getTelefono() { return telefono; }
string getFecha_Nacimiento() { return fecha_nacimiento; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

 Cn.abrir_conexion();
 cadena t = to_string(telefono);
		if (cn.getConectar()) {
 string insertar = "INSERTAR EN clientes(nit,nombres,apellidos,direccion, telefono, fecha_nacimiento) VALORES ('" + nit + "','  + nombres +  "',' + apellidos + "','  + direccion +  "',"  + t +  ","  + fecha_nacimiento + "')";
			const char* i = insertar.c_str();

 q_estado = mysql_query(cn.getConectar(), i);
			si(!q_estado) {
 cout << "Ingreso Exitoso ... " << endl;
			}
			más {
 cout << " xxx Error al Ingresar xxx" << endl;
			}
		}
		más {
 cout << " xxx Error en la Conexion xxxx" << endl;
		}
 Cn.cerrar_conexion();
	}
	leer vacío() {
		int q_estado;
		ConexionBD cn = ConexionBD();
 fila MYSQL_ROW;
		MYSQL_RES* resultado;
 Cn.abrir_conexion();

		if (cn.getConectar()) {

 cout << "------------ Datos de Clientes ------------" << endl;
 string consulta = "seleccione * de clientes";
			const char* c = consulta.c_str();
 q_estado = mysql_query(cn.getConectar(), c);
			si(!q_estado) {
 resultado = mysql_store_result(cn.getConectar());
				mientras que(fila = mysql_fetch_row(resultado)) {
 cout << fila[0] << ","  fila << [1] << "", << fila[2] << "", << fila[3] << "", << fila[4] << "", << fila[5] << "", << fila[6] << endl;
				}

			}
			más {
 cout << " xxx Error Consultar al xxx" << endl;
			}

		}
		más {
 cout << " xxx Error en la Conexion xxxx" << endl;
		}
 Cn.cerrar_conexion();
	}

	nulo() {
		int q_estado;
		ConexionBD cn = ConexionBD();
 fila MYSQL_ROW;
		MYSQL_RES* resultado;
 Cn.abrir_conexion();

		if (cn.getConectar()) {
			string idcliente, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
 cout << "------------------------------------------------" << endl;
 cout << "Ingrese el id del registro que desea modificar: ";
 cin >> idcliente;
 string consulta = "seleccione * de Clientes donde id_clientes=" + idcliente + "";
			const char* i = consulta.c_str();
 q_estado = mysql_query(cn.getConectar(), i);

			if(!q_estado) {

 resultado = mysql_store_result(cn.getConectar());

				mientras que(fila = mysql_fetch_row(resultado)) {

 cout << "Id Cliente: "  fila de << [0] << endl;
 cout << ("NIT: ") fila de << [1] << endl;
 cout << ("Desea modificarlo [s/n]: ");
 cin >> s;
					si((s == 's') || (s == 'S')) {
 cout << "\ningrese el nuevo nit del cliente: ";
 cin >> nit;
 string modificar = "update Clientes set nit = '' '  + nit +  "' donde id_clientes ="  + idcliente + "";
						const char* m = modificar.c_str();
 q_estado = mysql_query(cn.getConectar(), i);
					}
					más {
 cout << ("Modificacionexitosa" << endl;
					}
				}
			}
			más {
 cout << "Error al modificar\n";
			}
		}
		más {
 cout << "Error en la conexión\n";
		}
 Cn.cerrar_conexion();
	}

	void() {
		int q_estado;
		ConexionBD cn = ConexionBD();
 fila MYSQL_ROW;
		MYSQL_RES* resultado;
 Cn.abrir_conexion();

		if (cn.getConectar()) {
 idclientes de cadena;
 cout << "------------------------------------------------" << endl;
 cout << "Ingrese el id del registro que desea eliminar\n";
 cin >> idclientes;
 string eliminar = "eliminar de clientes donde id_clientes = (" + idclientes + ")";
			const char* i = eliminar.c_str();

 q_estado = mysql_query(cn.getConectar(), i);
			si(!q_estado) {
 cout << "Eliminación Exitosa ... " << endl;
			}
			más {
 cout << " xxx Error al eliminar xxx" << endl;
			}
		}
		más {
 cout << " xxx Error en la Conexion xxxx" << endl;
		}
 Cn.cerrar_conexion();
	}

	 };