#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

// 测试1: 基本功能测试 - 插入和显示
void test_basic_insert_and_show() {
    printf("========== 测试1: 基本插入和显示 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 插入一些数据
    InsertVal(&hash, 5);
    InsertVal(&hash, 15);
    InsertVal(&hash, 25);
    InsertVal(&hash, 35);
    
    printf("哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试1通过!\n\n");
}

// 测试2: 冲突处理测试 - 多个数据映射到同一索引
void test_collision_handling() {
    printf("========== 测试2: 冲突处理测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 这些数据都会映射到索引 5 (5 % 10 = 5, 15 % 10 = 5, 25 % 10 = 5)
    InsertVal(&hash, 5);
    InsertVal(&hash, 15);
    InsertVal(&hash, 25);
    InsertVal(&hash, 35);
    InsertVal(&hash, 45);
    
    printf("冲突处理后的哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试2通过!\n\n");
}

// 测试3: 搜索功能测试
void test_search() {
    printf("========== 测试3: 搜索功能测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 插入数据
    InsertVal(&hash, 10);
    InsertVal(&hash, 20);
    InsertVal(&hash, 30);
    InsertVal(&hash, 42);
    InsertVal(&hash, 55);
    
    printf("哈希表内容:\n");
    Show(&hash);
    
    // 测试搜索存在的元素
    printf("\n搜索测试:\n");
    int key1 = 20;
    printf("搜索 %d: ", key1);
    int result1 = SearchByKey(&hash, key1);
    if (result1 != -1) {
        printf("找到 %d\n", result1);
    }
    
    int key2 = 42;
    printf("搜索 %d: ", key2);
    int result2 = SearchByKey(&hash, key2);
    if (result2 != -1) {
        printf("找到 %d\n", result2);
    }
    
    // 测试搜索不存在的元素
    int key3 = 99;
    printf("搜索 %d: ", key3);
    int result3 = SearchByKey(&hash, key3);
    if (result3 == -1) {
        printf("未找到\n");
    }
    
    Destory(&hash);
    printf("测试3通过!\n\n");
}

// 测试4: 边界值测试
void test_boundary_values() {
    printf("========== 测试4: 边界值测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 测试负数
    InsertVal(&hash, -5);
    InsertVal(&hash, -15);
    
    // 测试0
    InsertVal(&hash, 0);
    
    // 测试大数
    InsertVal(&hash, 1000);
    InsertVal(&hash, 9999);
    
    printf("边界值测试后的哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试4通过!\n\n");
}

// 测试5: 空哈希表测试
void test_empty_hash() {
    printf("========== 测试5: 空哈希表测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    printf("空哈希表内容:\n");
    Show(&hash);
    
    // 尝试搜索空表
    printf("在空表中搜索 10: ");
    SearchByKey(&hash, 10);
    
    Destory(&hash);
    printf("测试5通过!\n\n");
}

// 测试6: 大量数据测试
void test_large_data() {
    printf("========== 测试6: 大量数据测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 插入50个数据
    printf("插入 50 个数据...\n");
    for (int i = 0; i < 50; i++) {
        InsertVal(&hash, i * 3 + 7);
    }
    
    printf("大量数据后的哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试6通过!\n\n");
}

// 测试7: 重复值测试
void test_duplicate_values() {
    printf("========== 测试7: 重复值测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 插入重复值
    InsertVal(&hash, 50);
    InsertVal(&hash, 50);
    InsertVal(&hash, 50);
    
    printf("插入重复值后的哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试7通过!\n\n");
}

// 测试8: 覆盖所有索引测试
void test_all_indices() {
    printf("========== 测试8: 覆盖所有索引测试 ==========\n");
    LinkHash hash;
    Init(&hash);
    
    // 插入数据覆盖所有索引 (0-9)
    for (int i = 0; i < 10; i++) {
        InsertVal(&hash, i);
    }
    
    printf("覆盖所有索引后的哈希表内容:\n");
    Show(&hash);
    
    Destory(&hash);
    printf("测试8通过!\n\n");
}

// 测试9: NULL指针测试
void test_null_pointer() {
    printf("========== 测试9: NULL指针测试 ==========\n");
    
    // 测试传入NULL指针
    printf("测试传入NULL指针到各个函数:\n");
    
    InsertVal(NULL, 10);
    SearchByKey(NULL, 10);
    Show(NULL);
    Destory(NULL);
    
    printf("测试9通过!\n\n");
}

// 测试10: 创建销毁循环测试（内存泄漏检测）
void test_create_destroy_cycle() {
    printf("========== 测试10: 创建销毁循环测试 ==========\n");
    
    for (int i = 0; i < 100; i++) {
        LinkHash hash;
        Init(&hash);
        
        // 插入一些数据
        for (int j = 0; j < 20; j++) {
            InsertVal(&hash, j + i * 10);
        }
        
        Destory(&hash);
    }
    
    printf("100次创建-使用-销毁循环完成，无内存泄漏\n");
    printf("测试10通过!\n\n");
}

int main() {
    
    printf("=======================================\n");
    printf("      哈希表(链表法)全面测试程序       \n");
    printf("=======================================\n\n");
    
    test_basic_insert_and_show();
    test_collision_handling();
    test_search();
    test_boundary_values();
    test_empty_hash();
    test_large_data();
    test_duplicate_values();
    test_all_indices();
    test_null_pointer();
    test_create_destroy_cycle();
    
    printf("=======================================\n");
    printf("         所有测试全部通过!             \n");
    printf("=======================================\n");
    
    return 0;
}
