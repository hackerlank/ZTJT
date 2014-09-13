//
//  UpdateAndBackupTableViewController.m
//  ZTJTApp
//
//  Created by Perry on 14-9-13.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "UpdateAndBackupTableViewController.h"
#import "TimeSetTableViewController.h"

@interface UpdateAndBackupTableViewController ()

@end

@implementation UpdateAndBackupTableViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"设备系统备份与升级";
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return 3;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = nil;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    // Configure the cell...
    switch (indexPath.row)
    {
        case 0:
        {
            cell.textLabel.text = @"编辑时钟";
        }
            break;
        case 1:
        {
            cell.textLabel.text = @"备份系统";
        }
            break;
        case 2:
        {
            cell.textLabel.text = @"升级系统";
        }
            break;
        default:
            break;
    }
    
    return cell;
}


- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch (indexPath.row)
    {
        case 0:
        {
            TimeSetTableViewController *ts = [[TimeSetTableViewController alloc] initWithStyle:UITableViewStyleGrouped];
            [self.navigationController pushViewController:ts animated:YES];
        }
            break;
        case 1:
        {
            
        }
            break;
        case 2:
        {
            
        }
            break;
        default:
            break;
    }
}

@end
