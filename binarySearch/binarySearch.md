# 二分查找算法详解
- [二分查找算法详解](#二分查找算法详解)
  - [1. 基本原理](#1-基本原理)
  - [2. 算法特点](#2-算法特点)
  - [3. C++实现范例](#3-c实现范例)
    - [3.1 迭代实现](#31-迭代实现)
    - [3.2 递归实现](#32-递归实现)
  - [4. 使用示例](#4-使用示例)
  - [5. 注意事项](#5-注意事项)
  - [6. 应用场景](#6-应用场景)

## 1. 基本原理

二分查找（Binary Search）是一种高效的查找算法，其核心思想是：通过将已排序的数据集分成两半，每次都与中间值比较，从而将查找范围缩小一半，直到找到目标值或确定目标值不存在。

让我为您生成一个流程图来展示二分查找的基本原理。

## 2. 算法特点

1. **前提条件**：
   - 待查找的数组必须是有序的
   - 数组支持随机访问

2. **时间复杂度**：
   - 最优时间复杂度：$O(1)$
   - 平均时间复杂度：$O(\log n)$
   - 最坏时间复杂度：$O(\log n)$

3. **空间复杂度**：
   - $O(1)$，只需要常数级别的额外空间

## 3. C++实现范例

### 3.1 迭代实现

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // 防止整数溢出
        
        if (nums[mid] == target) {
            return mid;  // 找到目标值，返回索引
        } else if (nums[mid] < target) {
            left = mid + 1;  // 目标值在右半部分
        } else {
            right = mid - 1;  // 目标值在左半部分
        }
    }
    
    return -1;  // 未找到目标值
}
```

### 3.2 递归实现

```cpp
int binarySearchRecursive(vector<int>& nums, int target, int left, int right) {
    if (left > right) {
        return -1;  // 基础情况：未找到目标值
    }
    
    int mid = left + (right - left) / 2;
    
    if (nums[mid] == target) {
        return mid;  // 找到目标值
    } else if (nums[mid] < target) {
        return binarySearchRecursive(nums, target, mid + 1, right);  // 在右半部分查找
    } else {
        return binarySearchRecursive(nums, target, left, mid - 1);  // 在左半部分查找
    }
}
```

## 4. 使用示例

```cpp
int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    
    // 迭代方式
    int result1 = binarySearch(nums, target);
    cout << "迭代方式查找结果：" << result1 << endl;  // 输出：3
    
    // 递归方式
    int result2 = binarySearchRecursive(nums, target, 0, nums.size() - 1);
    cout << "递归方式查找结果：" << result2 << endl;  // 输出：3
    
    return 0;
}
```

## 5. 注意事项

1. **边界条件处理**：
   - 注意数组为空的情况
   - 注意只有一个元素的情况
   - 注意目标值不在数组范围内的情况

2. **中间位置计算**：
   - 使用 `mid = left + (right - left) / 2` 而不是 `mid = (left + right) / 2`
   - 这样可以防止 `left + right` 可能导致的整数溢出

3. **循环条件**：
   - 使用 `left <= right` 而不是 `left < right`
   - 确保能够处理所有可能的情况

## 6. 应用场景

1. 在有序数组中查找特定元素
2. 在有序数组中查找插入位置
3. 在旋转有序数组中查找元素
4. 在二分答案的问题中使用（如求平方根）