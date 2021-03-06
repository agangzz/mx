// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"
#include "mxtest/core/PlayTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, Play )
{
    TestMode v = TestMode::one;
	PlayPtr object = tgenPlay( v );
	stringstream expected;
	tgenPlayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, Play )
{
    TestMode v = TestMode::two;
	PlayPtr object = tgenPlay( v );
	stringstream expected;
	tgenPlayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, Play )
{
    TestMode v = TestMode::three;
	PlayPtr object = tgenPlay( v );
	stringstream expected;
	tgenPlayExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    PlayPtr tgenPlay( TestMode v )
    {
        PlayPtr o = makePlay();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->setChoice( Play::Choice::mute );
                o->getMute()->setValue( MuteEnum::hat );
            }
                break;
            case TestMode::three:
            {
                o->setChoice( Play::Choice::otherPlay );
                o->getOtherPlay()->setValue( XsString( "SomeString" ) );
                o->getOtherPlay()->getAttributes()->type = XsToken( "sometype" );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenPlayExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<play>)" );
                streamLine( os, i+1, R"(<ipa></ipa>)" );
                streamLine( os, i, R"(</play>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<play>)" );
                streamLine( os, i+1, R"(<mute>hat</mute>)" );
                streamLine( os, i, R"(</play>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<play>)" );
                streamLine( os, i+1, R"(<other-play type="sometype">SomeString</other-play>)" );
                streamLine( os, i, R"(</play>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
