/**
 * @file    test_rest_api.cpp
 * @brief
 * @author  Bryan Bartley
 * @email   bartleyba@sbolstandard.org
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBOL.  Please visit http://sbolstandard.org for more
 * information about SBOL, and the latest version of libSBOL.
 *
 *  Copyright 2016 University of Washington, WA, USA
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ------------------------------------------------------------------------->*/

#define BASE_URI "http://sys-bio.org"

#include "sbol.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;
using namespace sbol;

int main()
{
    setHomespace(BASE_URI);
    Document& doc = *new Document();
    
    PartShop& igem = *new PartShop("http://synbiohub.org");
//    ComponentDefinition& cdef = igem.pull<ComponentDefinition>("http://synbiohub.org/public/igem/BBa_K123000/1");
//    map<string, string> q_args = {{"objectType", SBOL_COMPONENT_DEFINITION}};
//    SearchQuery& q = *new SearchQuery(q_args);
    
    SearchQuery& q = *new SearchQuery();
    q[SBOL_ROLES].set(SO_PROMOTER);
//    q[SBOL_ROLES].add(SO_RBS);
    for (auto & role : q[SBOL_ROLES])
        cout << role << endl;
    //doc.add<SearchQuery_>(q_);
    
    igem.search(q);
    q.addToDocument(doc);
    doc.write("search_query_example.xml");
}