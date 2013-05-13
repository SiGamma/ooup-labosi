#!/usr/bin/env python

import os
import imp

def myfactory (moduleName, name):
  (f, path, desc) = imp.find_module(moduleName, ['plugins'])

  create = getattr(imp.load_module (moduleName, f, path, desc), 'create')
  return create()

def printGreeting(animal):
  animal.printGreeting()

def printMenu(animal):
  animal.printMenu()

def test():
  pets=[]
  # obidji svaku datoteku kazala plugins 
  for mymodule in os.listdir('plugins'):
    moduleName, moduleExt = os.path.splitext(mymodule)
    # ako se radi o datoteci s Pythonskim kodom ...
    if moduleExt=='.py':
      # instanciraj ljubimca ...
      ljubimac=myfactory((moduleName), 'Ljubimac '+str(len(pets)))
      # ... i dodaj ga u listu ljubimaca
      pets.append(ljubimac)

  # ispisi ljubimce
  for pet in pets:
    printGreeting(pet)
    printMenu(pet)

test()
