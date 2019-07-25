# AdskPoly 

Copyright 2019 Autodesk, Inc.  All rights reserved.

Use of this software is subject to the terms of the Autodesk license 
agreement provided at the time of installation or download, or which 
otherwise accompanies this software in either electronic or hard copy form.   


The polysamp application demonstrates several things:

- How to implement a custom entity class (polyobj project).
- How transactions work (polyui project).
- How to use the AcDbEntity::highlight() and AcDbEntity::unHighlight()    
- How to implement AcDbAssocPersSubentIdPE for a custom entity. 
    This protocol extention reveals subentities of the entity to the 
    Associative Framework. When the entity exposes this protocol extension, 
    it can participate in associative relations represented by the Associative 
    Framework, such as geometric and dimensional constraints can be created 
    between the custom entities and other entities in the drawing.

- How to implement AcDbAssocPersSubentIdPE::createNewPersSubent() so that
    the returned AcDbAssocPersSubentId persistently identifies the subentity
    of the custom entity. When the topology of the entity changes (number of 
    sides changes), AcDbAssocPersSubentIdPE::getTransientSubentIds() takes
    the AcDbAssocPersSubentId and returns a "corresponding" subentity in the
    current state of the entity.

-  How to make a custom entity constrainable by using a general and 
    reusable ConstrainedRigidEntityAssocPersSubentIdPE class that
    handles the case when the constrained custom entity changes shape
    during dragging.

- How to allow associative dimensions on a custom entity by the custom
    entity exposing AcDbAssocPersSubentIdPE.
    

### Steps To Build
```bash
git clone https://github.com/MadhukarMoogala/adskpoly.git
cd  adskpoly
start notepad asdkpoly.vcxproj
change <ObjectARXPath>D:\Work\ObjectARX20$(ArxVersion)</ObjectARXPath> to your SDK path
devenv asdkpoly.vcxproj
msbuild /t:build /p:Configuration=Debug;Platform=x64 asdkpoly.vcxproj
```

