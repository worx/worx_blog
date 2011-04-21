<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function worx_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog entries
  $permissions['create blog entries'] = array(
    'name' => 'create blog entries',
    'roles' => array(
      '0' => 'blog administrator',
      '1' => 'trusted blogger',
      '2' => 'untrusted blogger',
    ),
  );

  // Exported permission: delete any blog entry
  $permissions['delete any blog entry'] = array(
    'name' => 'delete any blog entry',
    'roles' => array(
      '0' => 'blog administrator',
    ),
  );

  // Exported permission: delete own blog entries
  $permissions['delete own blog entries'] = array(
    'name' => 'delete own blog entries',
    'roles' => array(
      '0' => 'blog administrator',
      '1' => 'trusted blogger',
      '2' => 'untrusted blogger',
    ),
  );

  // Exported permission: edit any blog entry
  $permissions['edit any blog entry'] = array(
    'name' => 'edit any blog entry',
    'roles' => array(
      '0' => 'blog administrator',
    ),
  );

  // Exported permission: edit own blog entries
  $permissions['edit own blog entries'] = array(
    'name' => 'edit own blog entries',
    'roles' => array(
      '0' => 'blog administrator',
      '1' => 'trusted blogger',
      '2' => 'untrusted blogger',
    ),
  );

  return $permissions;
}
