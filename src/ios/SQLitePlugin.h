/*
 * Copyright (c) 2012-2016: Christopher J. Brody (aka Chris Brody)
 * Copyright (C) 2011 Davide Bertola
 *
 * This library is available under the terms of the MIT License (2008).
 * See http://opensource.org/licenses/alphabetical for full text.
 */

#import <Cordova/CDVPlugin.h>

// Used to remove dependency on sqlite3.h in this header:
struct sqlite3;

enum WebSQLError {
    WEBSQL_UNKNOWN_ERR = 0,
    WEBSQL_DATABASE_ERR = 1,
    WEBSQL_VERSION_ERR = 2,
    WEBSQL_TOO_LARGE_ERR = 3,
    WEBSQL_QUOTA_ERR = 4,
    WEBSQL_SYNTAX_ERR = 5,
    WEBSQL_CONSTRAINT_ERR = 6,
    WEBSQL_TIMEOUT_ERR = 7
};
typedef int WebSQLError;

@interface SQLitePlugin : CDVPlugin {
    NSMutableDictionary *openDBs;
}

@property (nonatomic, copy) NSMutableDictionary *openDBs;

// Self-test
-(void) echoStringValue: (CDVInvokedUrlCommand*)command;

// Open / Close / Delete
-(void) open: (CDVInvokedUrlCommand*)command;
-(void) close: (CDVInvokedUrlCommand*)command;
-(void) delete: (CDVInvokedUrlCommand*)command;

-(void) openNow: (CDVInvokedUrlCommand*)command;
-(void) closeNow: (CDVInvokedUrlCommand*)command;
-(void) deleteNow: (CDVInvokedUrlCommand*)command;

// Batch processing interface
-(void) backgroundExecuteSqlBatch: (CDVInvokedUrlCommand*)command;

-(void) executeSqlBatchNow: (CDVInvokedUrlCommand*)command;

@end /* vim: set expandtab : */
