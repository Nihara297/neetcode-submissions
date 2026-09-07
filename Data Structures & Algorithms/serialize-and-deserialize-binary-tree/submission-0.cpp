class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }

    TreeNode* build(string &s, int &i) {

        if(s[i] == '#') {
            i += 2;
            return NULL;
        }

        int sign = 1;

        if(s[i] == '-') {
            sign = -1;
            i++;
        }

        int num = 0;

        while(s[i] != ',') {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        i++;

        TreeNode* root = new TreeNode(sign * num);

        root->left = build(s, i);
        root->right = build(s, i);

        return root;
    }
};