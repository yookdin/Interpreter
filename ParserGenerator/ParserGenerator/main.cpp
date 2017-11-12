//
//  main.cpp
//  ParserGenerator
//
//  Created by Yuval Dinari on 7/21/16.
//  Copyright © 2016 Vonage. All rights reserved.
//

#include "LALR_TableGenerator.hpp"

int main(int argc, const char * argv[]) {
    
    try {
        string project_dir(getenv("SRCROOT"));
        
        if(project_dir.empty())
            throw string("Couldn't get project dir");
        
        string workspace_dir = project_dir + "/..";
        LALR_TableGenerator(workspace_dir + "/grammar_definition", workspace_dir + "/InterpreterRuntime/InterpreterRuntime/ParserTables.cpp");
        
    } catch(string& err) {
        cout << "Caught exception: " << err << endl;
    }
    
    return 0;
}
