#include "stdafx.h"
#include "CppUnitTest.h"
#include "AttributID.h"
#include "AttributNum.h"
#include <string>
#include "Signature.h"
#include "Maladie.h"
#include "Patient.h"
#include "Analyse.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//test pour class Signature getIdsignature() et AjouterAttribut()
			string ID = "11111";
			string name = "ID";
			AttributID *aID = new AttributID(ID, name);
			Signature s;
			s.AjouterAttribut(aID);
			int id = s.getIdSignature();

			Assert::AreEqual(
				11111,
				id


			);
		}
		TEST_METHOD(TestMethod2)
		{
			//test pour la class Analyse risqueNumerique()
			string name1 = "NUM";
			
			AttributNum *aNum = new AttributNum("10", name1);
			vector <Attribut*> va;
			va.push_back(aNum);
			Analyse *a = new Analyse();
			vector<double> d;
			d.push_back(a->risqueNumerique(aNum, va).front());
			
			
			Assert::AreEqual(
				1.0,
				d[0],
				0.1

			);
		}
		TEST_METHOD(TestMethod3)
		{
			//test pour la class Analyse risqueCategorique()

			AttributCarac *aCate = new AttributCarac("true", "cate");
			vector <Attribut*> va;
			va.push_back(aCate);
			Analyse *a = new Analyse();
			vector<double> d;
			d.push_back(a->risqueCategorique(aCate, va).front());


			Assert::AreEqual(
				0.0,
				d[0],
				0.1

			);
		}
		TEST_METHOD(TestMethod4)
		{
			//test pour class Signature getTabAttribut()
			Signature s;
			AttributCarac *aCate = new AttributCarac("true", "cate");
			vector <Attribut*> va;
			va.push_back(aCate);
			s.AjouterAttribut(aCate);
			vector<Attribut *>va1 = s.getTabAttributs();
			


			Assert::AreEqual(
				va1==va,
				true
				

			);
		}
		TEST_METHOD(TestMethod5)
		{
			//test pour class Maladie getNom()
			Signature s;
			Maladie *m = new Maladie("lenom",s);
			string nom = m->getNom();



			Assert::AreEqual(
				nom == "lenom",
				true


			);
		}
		TEST_METHOD(TestMethod6)
		{
			//test pour class Maladie getSignature()
			string ID = "11111";
			string name = "ID";
			AttributID *aID = new AttributID(ID, name);
			Signature s;
			s.AjouterAttribut(aID);
			Maladie *m = new Maladie("lenom", s);
			Signature s1 = m->getSignature();
			


			Assert::AreEqual(
				s1.getIdSignature() == s.getIdSignature(),
				true


			);
		}
		TEST_METHOD(TestMethod7)
		{
			//test pour class Patient getSignature()
			string ID = "11111";
			string name = "ID";
			AttributID *aID = new AttributID(ID, name);
			Signature s;
			s.AjouterAttribut(aID);
			Patient *p = new Patient(s);
			Signature s1 = p->getSignature();



			Assert::AreEqual(
				s1.getIdSignature() == s.getIdSignature(),
				true


			);
		}
		TEST_METHOD(TestMethod8)
		{
			//test d'integration pour class Analyse FaireAnalyse ()
			
			Signature s;
			AttributNum *aNum = new AttributNum("10", "lenom");
			s.AjouterAttribut(aNum);
			Patient p = Patient(s);
			Maladie m = Maladie("lenom",s);
			vector<Maladie> vm;
			vm.push_back(m);
			Analyse a = Analyse();
			Patient p1 = a.FaireAnalyse(p,vm);
			multimap<string, double> map;
			map.insert(pair<string,double>("lenom", 0.0));
			Assert::AreEqual(
				p1.getRisqueMaladies() == map,
				true


			);
		}
		
	};
}