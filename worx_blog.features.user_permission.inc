<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function worx_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog entries
  $permissions['create blog entries'] = array(
    'name' => 'create blog entries',
    'roles' => array(),
  );

  // Exported permission: delete any blog entry
  $permissions['delete any blog entry'] = array(
    'name' => 'delete any blog entry',
    'roles' => array(),
  );

  // Exported permission: delete own blog entries
  $permissions['delete own blog entries'] = array(
    'name' => 'delete own blog entries',
    'roles' => array(),
  );

  // Exported permission: edit any blog entry
  $permissions['edit any blog entry'] = array(
    'name' => 'edit any blog entry',
    'roles' => array(),
  );

  // Exported permission: edit own blog entries
  $permissions['edit own blog entries'] = array(
    'name' => 'edit own blog entries',
    'roles' => array(),
  );

  // Exported permission: publish blogs without review
  $permissions['publish blogs without review'] = array(
    'name' => 'publish blogs without review',
    'roles' => array(),
  );

  // Exported permission: update blogs without review
  $permissions['update blogs without review'] = array(
    'name' => 'update blogs without review',
    'roles' => array(),
  );

  return $permissions;
}
