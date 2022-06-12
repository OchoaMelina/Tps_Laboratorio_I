#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = - 1 ;
	int retornoLeido;
	char buffer[6][104];
	Passenger* pPassenger= NULL ;

	if (pFile!= NULL && pArrayListPassenger!= NULL )
	{
		fscanf (pFile, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^ \n ] \n " ,buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
		do
		{
			retornoLeido = fscanf(pFile, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^ \n ] \n " ,buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
			if(retornoLeido<6 )
			{
				Passenger_delete(pPassenger);
				retorno=-1;
				break;
			}
			else
			{
				pPassenger = Passenger_newParametros (buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
				if (pPassenger!= NULL )
				{
					ll_add (pArrayListPassenger,pPassenger);
					retorno= 0 ;
				}
			}
		} while (! feof (pFile));
	}

	return retorno;

}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int retornoLeido;
	Passenger* pPassenger=NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			pPassenger=Passenger_new();
			if(pPassenger!=NULL)
			{
				retornoLeido = fread(pPassenger,sizeof(Passenger),1,pFile);
				if(retornoLeido!=1)
				{
					Passenger_delete(pPassenger);
					break;
				}
				else
				{
					ll_add(pArrayListPassenger,pPassenger);
					retorno=0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
