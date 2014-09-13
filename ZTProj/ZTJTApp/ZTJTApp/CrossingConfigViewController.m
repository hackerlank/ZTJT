//
//  CrossingConfigViewController.m
//  ZTJTApp
//
//  Created by Perry on 14-9-7.
//  Copyright (c) 2014年 Perry. All rights reserved.
//

#import "CrossingConfigViewController.h"
#import "CrossingProfileTableViewController.h"

@interface CrossingConfigViewController ()

@end

@implementation CrossingConfigViewController

#pragma mark - Public
- (void) setCrossing:(Crossing *)crossing
{
    if (nil == crossing)
    {
        assert(0);
    }
    _crossing = crossing;
}


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
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    //static NSString *cellIndentifier = @"Cell";
    //UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIndentifier forIndexPath:indexPath];
    UITableViewCell *cell = nil;
    // Configure the cell...
    if (nil == cell)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    }
    
    switch (indexPath.row)
    {
        case 0:
            cell.textLabel.text = @"基本属性";
            break;
        case 1:
            cell.textLabel.text = @"设备系统备份与升级";
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
            CrossingProfileTableViewController *profile = [[CrossingProfileTableViewController alloc] initWithStyle:UITableViewStyleGrouped];
            [profile setCrossing:_crossing];
            [self.navigationController pushViewController:profile animated:YES];
        }
            break;
        case 1:
        {
            
        }
        default:
            break;
    }
}

@end
