import sys,os
import xml.etree.ElementTree as ET
from GenFee import GenFee

__all__ = ['GenNvM']


__Header = \
"""/*
* Configuration of module: NvM
*
* Created by:   parai          
* Copyright:    (C)parai@foxmail.com  
*
* Configured for (MCU):    MinGW ...
*
* Module vendor:           ArcCore
* Generator version:       2.0.34
*
* Generated by easySAR Studio (https://github.com/parai/OpenSAR)
*/
"""

__dir = '.'
__root = None

def GenNvM(wfxml):
    global __dir,__root
    __root = ET.parse(wfxml).getroot();
    __dir = os.path.dirname(wfxml)
    GenFee(wfxml)
    print '>>> Gen NvM DONE <<<'


def tInt(strnum):
    if(strnum.find('0x')!=-1 or strnum.find('0X')!=-1):
        return int(strnum,16)
    else:
        return int(strnum,10)
    
