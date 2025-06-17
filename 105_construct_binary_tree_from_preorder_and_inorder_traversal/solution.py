from typing import List

from typing_extensions import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        index_map = {num: i for i, num in enumerate(inorder)}
        pre_iter = iter(preorder)

        def build(pre_lo, pre_hi) -> Optional[TreeNode]:
            if pre_lo > pre_hi:
                return None
            root_val = next(pre_iter)
            root = TreeNode(root_val)
            mid = index_map[root_val]
            root.left = build(pre_lo, mid - 1)
            root.right = build(mid + 1, pre_hi)
            return root

        return build(0, len(inorder) - 1)
