#ifndef TECH_ESTIMATOR
#define TECH_ESTIMATOR
#include "serialized_tables.h"
#include <vector>
#include <set>
#include <string>

/***
 ***********************
 *openingsProba content*
 ***********************
 |=============|
 |Ben's labels:| (extracted with rules)
 |=============|

 Terran openings, in order (in the vector):
 - Bio
 - TwoFactory
 - VultureHarass
 - SiegeExpand
 - Standard
 - FastDropship
 - Unknown

 Protoss openings, in order (in the vector):
 - FastLegs
 - FastDT
 - FastObs
 - ReaverDrop
 - Carrier
 - FastExpand
 - Unknown

 Zerg openings, in order (in the vector):
 - TwoHatchMuta
 - ThreeHatchMuta
 - HydraRush
 - Standard
 - HydraMass
 - Lurker
 - Unknown

 |==========|
 |My labels:| (extracted by clustering)
 |==========|

 Terran openings, in order (in the vector):
 - bio
 - rax_fe
 - two_facto
 - vultures
 - drop
 - unknown

 Protoss openings, in order (in the vector):
 - two_gates
 - fast_dt
 - templar
 - speedzeal
 - corsair
 - nony
 - reaver_drop
 - unknown

 Zerg openings, in order (in the vector):
 - fast_mutas
 - mutas
 - lurkers
 - hydras
 - unknown
 */

class tech_estimator 
{
    serialized_tables st;
    void loadTable(const char* tname);
    std::vector<long double> openingsProbas; // see the big fat comment above
    std::set<int> buildingsTypesSeen;
    bool notFirstOverlord;
    std::set<std::string> _alreadySawUnitTypes;
    inline bool alreadySaw(const std::string& ut);
    bool insertBuilding(const std::string& ut);
    void computeDistribOpenings(int time);
    inline bool testBuildTreePossible(int indBuildTree,
            const std::set<int>& setObs);
    public:
    tech_estimator(const std::string& matchup);
    ~tech_estimator();
    const std::vector<long double>& getOpeningsProbas() const;
    bool hasInfered;
    void onUnitShow(const std::string& unit_name, int frame);
    void dump_vector_X();
};
#endif
