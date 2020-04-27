// Seminar4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Auto.h"

using std::vector;
using std::exception;
using std::string;
using std::cin;
using std::cout;

/**
* CRUD operations repository interface
*/
template <class E>
class CrudRepository {
public:
    
    /**
    * @param id -the id of the entity to be returned id must not be null
    * @return the entity with the specified id or null - if there is no entity with the given id
    *
    */
    virtual E findOne(int id) = 0;
    
    /**
    * @return all entities
    */
    virtual vector< E > findAll() = 0;
    
    /**
    * @param entity entity must be not null
    * @return null- if the given entity is saved otherwise returns the entity (id already exists)
    *
    */
    virtual E save(E entity) = 0;
    
    /**
    * removes the entity with the specified id
    *
    * @param id id must be not null
    * @return the removed entity or null if there is no entity with the given id
    *
    */
    virtual E del(int id) = 0;
    
    /**
    * @param entity entity must not be null
    * @return null - if the entity is updated, otherwise returns the entity - (e.g id does not exist).
    *
    */
    virtual E update(E entity) = 0;
    
    virtual ~CrudRepository() {};
};



class AutoInMemoryRepository: public CrudRepository<Auto>   //Auto* ;
{
private:
    vector<Auto> vehicles;                                  //Auto* ...;

public:
    
    // void setVehicles(vector<Auto> value) {vehicles = value;}

    Auto findOne(int id)            //Auto* ... return nullptr;
    {
        int l = vehicles.size();
        for (int i = 0; i < l; i++)
            if (vehicles[i].getId() == id) return vehicles[i];
        // return NULL;
        exception e;
        throw e;        // return optional ( Java )
    }

    vector< Auto > findAll()
    {
        return vehicles;
    }
    
    Auto save(Auto entity)
    {
        int l = vehicles.size();
        for (int i = 0; i < l; i++)
            if (entity.getId() == vehicles[i].getId()) 
            { 
                // return NULL; 
                exception f;
                throw f;
                //cout << " exceptie: nu s a gasit!";
            }
        cout << "trece" << '\n';
        vehicles.push_back(entity);
        return entity;                  //
    }

    Auto del(int id)
    {
        int l = vehicles.size();
        for (int i = 0; i < l; i++)
            if (vehicles[i].getId() == id)
            {
                cout << "intra\n";
                Auto aux = vehicles[i];
                vehicles.erase(vehicles.begin() + i);
                return aux;
            }
                //return NULL;
        exception g; throw g;
        // return ;
    }

    Auto update(Auto entity)
    {
        int l = vehicles.size();
        for (int i = 0; i < l; i++)
            if (vehicles[i].getId() == entity.getId())
            {
                cout << "exceptie\n";
                vehicles[i] = entity;
                // return NULL;
                // exception h; throw h
            }
        return entity;
    }

};

int main()
{

    CrudRepository<Auto>* p = new AutoInMemoryRepository;   // aici p pointeaza spre un obiect de tip CrudRepository!! nu vede ce e al lui

    //p->findAll();
    /*
    try
    {
        cout << "intra";
        p->save(Auto{1,"Lambo","Huracan"});
    }
    catch (exception&)
    {
        cout << "intra2";
        std::cout << "Arunca exceptii";
    }
    */

    Auto a1{ 1,"Dacia","Logan" };
    p->save(a1);
    Auto a2{ 2,"Ferrari","Enzo" };
    p->save(a2);
    Auto a3{ 3,"Renault","Megane" };
    p->save(a3);
    Auto a4{ 4,"Daewoo","Matiz" };
    p->save(a4);

    
    vector<Auto> aux;
    aux = p->findAll();
    for (int i = 0; i < 4; i++)
        cout << aux[i] << '\n';

    p->update(Auto(1, "Ferrari", "Spyder"));

    p->del(2);
    aux = p->findAll();
    
    cout << '\n';
    for (int i = 0; i < aux.size(); i++)
        cout << aux[i] << '\n';


    
    /*
    vector<Auto> lista = { a1,a2,a3,a4 };
    p->setVehicles(lista);
    */

    delete p;
}

// intre controller si repository tre sa fie o relatie de aggregation!!