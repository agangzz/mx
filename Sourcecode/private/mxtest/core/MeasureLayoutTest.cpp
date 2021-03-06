// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mx/core/Elements.h"
#include "mxtest/core/MeasureLayoutTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, MeasureLayout )
{
    TestMode v = TestMode::one;
	MeasureLayoutPtr object = tgenMeasureLayout( v );
	stringstream expected;
	tgenMeasureLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, MeasureLayout )
{
    TestMode v = TestMode::two;
	MeasureLayoutPtr object = tgenMeasureLayout( v );
	stringstream expected;
	tgenMeasureLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, MeasureLayout )
{
    TestMode v = TestMode::three;
	MeasureLayoutPtr object = tgenMeasureLayout( v );
	stringstream expected;
	tgenMeasureLayoutExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( ! object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    MeasureLayoutPtr tgenMeasureLayout( TestMode v )
    {
        MeasureLayoutPtr o = makeMeasureLayout();
        switch ( v )
        {
            case TestMode::one:
            {
                ;
            }
                break;
            case TestMode::two:
            {
                o->setHasMeasureDistance( true );
                o->setMeasureDistance( makeMeasureDistance( TenthsValue( 13.43 ) ) );
            }
                break;
            case TestMode::three:
            {
                o->setHasMeasureDistance( true );
                o->setMeasureDistance( makeMeasureDistance( TenthsValue( -1 ) ) );
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenMeasureLayoutExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<measure-layout></measure-layout>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<measure-layout>)" );
                streamLine( os, i+1, R"(<measure-distance>13.43</measure-distance>)" );
                streamLine( os, i, R"(</measure-layout>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<measure-layout>)" );
                streamLine( os, i+1, R"(<measure-distance>-1</measure-distance>)" );
                streamLine( os, i, R"(</measure-layout>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif

