<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _worx_blog_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_default_page_manager_pages().
 */
function _worx_blog_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_blog';
  $page->task = 'page';
  $page->admin_title = 'Create Blog';
  $page->admin_description = '';
  $page->path = 'blog/add_blog';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create blog entries',
        ),
        'context' => 'logged-in-user',
      ),
      '1' => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            '0' => 3,
            '1' => 5,
            '2' => 6,
            '3' => 7,
            '4' => 4,
          ),
        ),
        'context' => 'logged-in-user',
      ),
    ),
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Create Blog',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_blog_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'add_blog';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'node_create_menu',
    'context_admin_options_items' => 'blog',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_blog'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog_admin';
  $page->task = 'page';
  $page->admin_title = 'Blog Administration';
  $page->admin_description = '';
  $page->path = 'blog/admin';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
      ),
      '1' => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            '0' => 3,
            '1' => 5,
            '2' => 4,
          ),
        ),
        'context' => 'logged-in-user',
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Administer',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_blog_admin_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'blog_admin';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'context_admin_options' => 'views_bulk_menu',
    'context_admin_vbo_views_bulk_node_type' => 'blog',
    'context_admin_vbo_views_bulk_published' => 'both',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog_admin'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog_user_admin';
  $page->task = 'page';
  $page->admin_title = 'Blog User Administration';
  $page->admin_description = '';
  $page->path = 'blog/users/admin';
  $page->access = array(
    'plugins' => array(
      '0' => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            '0' => 3,
            '1' => 5,
            '2' => 4,
          ),
        ),
        'context' => 'logged-in-user',
      ),
      '1' => array(
        'name' => 'php',
        'settings' => array(
          'description' => '',
          'php' => 'global $user;
          
          if ($user->uid == 1) {
            return TRUE;
          }
          return FALSE;',
        ),
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Administer',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'tab',
      'title' => 'Users',
      'name' => 'navigation',
      'weight' => '11',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_blog_user_admin_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'blog_user_admin';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          '0' => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          '0' => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          '0' => 'center',
          '1' => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '66.02164731487797',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '33.97835268512203',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
    ),
  );
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = 'User Administration';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'blog_user_admin';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_user_admin-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['right'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_user_admin-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-3'] = $pane;
    $display->panels['right'][1] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_user_admin-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-4'] = $pane;
    $display->panels['right'][2] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog_user_admin'] = $page;

 return $pages;

}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _worx_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog entries
  $permissions[] = array(
    'name' => 'create blog entries',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'blog administrator',
      '2' => 'trusted blogger',
      '3' => 'untrusted blogger',
      '4' => 'webmaster',
    ),
  );

  // Exported permission: delete any blog entry
  $permissions[] = array(
    'name' => 'delete any blog entry',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'blog administrator',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: delete own blog entries
  $permissions[] = array(
    'name' => 'delete own blog entries',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'blog administrator',
      '2' => 'trusted blogger',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: edit any blog entry
  $permissions[] = array(
    'name' => 'edit any blog entry',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'blog administrator',
      '2' => 'webmaster',
    ),
  );

  // Exported permission: edit own blog entries
  $permissions[] = array(
    'name' => 'edit own blog entries',
    'roles' => array(
      '0' => 'administrative user',
      '1' => 'blog administrator',
      '2' => 'trusted blogger',
      '3' => 'webmaster',
    ),
  );

  // Exported permission: publish blogs without review
  $permissions[] = array(
    'name' => 'publish blogs without review',
    'roles' => array(
      '0' => 'blog administrator',
      '1' => 'trusted blogger',
    ),
  );

  // Exported permission: update blogs without review
  $permissions[] = array(
    'name' => 'update blogs without review',
    'roles' => array(
      '0' => 'blog administrator',
      '1' => 'trusted blogger',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _worx_blog_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog';
  $strongarm->value = '4';

  $export['comment_default_mode_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog';
  $strongarm->value = array(
    '0' => 'status',
  );

  $export['node_options_blog'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = 'blog/[title-raw]';

  $export['pathauto_node_blog_pattern'] = $strongarm;
  return $export;
}
