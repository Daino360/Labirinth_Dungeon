//
// Created by Stefano on 22/11/2017.
//

#ifndef PLATFORMDUNGEON_EQUIPMENT_H
#define PLATFORMDUNGEON_EQUIPMENT_H

#include <iostream>
#include "EnumFile.h"

//Equipaggiamento di armature
class Equipment {
public:
    Equipment(int m, int st); //m-material, st-strenght
    int dress();
    int st;

void strenghtForMaterial (){
    if (materialEquipment == wood){
        st=1;
    }
    else if (materialEquipment == iron){
        st=3;
    }
    else if (materialEquipment == steel){
        st=5;
    }
    else if (materialEquipment ==valyria){
        st=10;
    }
}



private:
    int strenght;// diversa a seconda del materiale
    int materialEquipment;//Materiale dell' armatura : Legno, Ferro, Acciaio e valyria FARE ANCHE QUESTO CON L ENUMERAZIONE

};


#endif //PLATFORMDUNGEON_EQUIPMENT_H
